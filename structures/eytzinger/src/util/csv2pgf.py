#!/usr/bin/env python3
"""
csv2pgfplots.py  –  Generate LaTeX \addplot coordinates from a CSV

Usage:
    python csv2pgfplots.py path/to/file.csv column_name [--impls I1 I2 ...]
"""

import argparse
import sys
import textwrap
import pandas as pd


parser = argparse.ArgumentParser(
    formatter_class=argparse.RawDescriptionHelpFormatter,
    description=textwrap.dedent("""
        Convert a CSV produced by the BST benchmark into pgfplots commands.

        • The x–axis is n (dataset size).
        • The y–axis is the column you name on the command line.
        • One \addplot is generated for every implementation.
    """),
)
parser.add_argument("csv",  help="Input CSV file")
parser.add_argument("column", help="Column to plot on the y‑axis")
parser.add_argument(
    "--impls",
    nargs="+",
    default=[
        "BST_VEB",
        "BST_EYT",
        "BST_EYT_PREF",
        "BST_EYT_PREF_TWO",
        "BST_EYT_PREF_THREE",
        "BST_EYT_PREF_FOUR",
        "BST_EYT_PREF_PROB",
    ],
    help="Implementations to include (in legend order)",
)
args = parser.parse_args()


styles = {
    "BST_VEB":            dict(color="red",    line="dotted",        mark="triangle*"),
    "BST_EYT":            dict(color="blue",   line="dashed",        mark="square*"),
    "BST_EYT_PREF":       dict(color="green!70!black", line="solid",       mark="*"),
    "BST_EYT_PREF_TWO":   dict(color="orange", line="dashdotted",    mark="diamond*"),
    "BST_EYT_PREF_THREE": dict(color="purple", line="loosely dotted", mark="pentagon*"),
    "BST_EYT_PREF_FOUR":  dict(color="brown",  line="densely dashed", mark="x*"),
    "BST_EYT_PREF_PROB":  dict(color="black",  line="densely dotted", mark="o"),
}

missing = [impl for impl in args.impls if impl not in styles]
if missing:
    sys.exit(f"Error: no style defined for {', '.join(missing)}")

try:
    df = pd.read_csv(args.csv)
except (FileNotFoundError, pd.errors.ParserError) as e:
    sys.exit(f"Cannot read CSV: {e}")

required_cols = {"impl", "n", args.column}
if not required_cols.issubset(df.columns):
    sys.exit(f"CSV must contain the columns {', '.join(required_cols)}")

df["n"] = pd.to_numeric(df["n"], errors="coerce")
df[args.column] = pd.to_numeric(df[args.column], errors="coerce")


if args.column.lower().endswith("rate"):
    df[args.column] *= 100


for impl in args.impls:
    block = df[df["impl"] == impl].sort_values("n")
    if block.empty:
        print(f"% Warning: {impl} not found in CSV", file=sys.stderr)
        continue

    sty = styles[impl]
    header = (
        f"\\addplot+["
        f"{sty['color']}, thick, {sty['line']}, "
        f"mark={sty['mark']}, mark options={{scale=.7,fill={sty['color']}}}"
        f"]"
    )
    print(header)
    print("  coordinates {")
    for n, y in zip(block["n"], block[args.column]):
        print(f"    ({int(n)},{y:.6g})")
    print("  };")
    safe_impl = impl.replace('_', r'\_')  
    print(f"\\addlegendentry{{{safe_impl}}}\n")
