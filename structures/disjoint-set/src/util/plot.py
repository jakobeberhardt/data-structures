#!/usr/bin/env python3
# ------------------------------------------------------------------
#  Usage:
#     python plot.py  <variant> <column>  <small> <medium> <large>
#
#     example:
#     python plot.py  UR_PS  Cost_per_n   data/small.txt \
#                                               data/medium.txt \
#                                               data/large.txt

import sys, csv, re
from textwrap import indent

def read_section(path, tag):
    """Return list of dict rows (CSV) for the first === TAG === block."""
    pat = re.compile(rf"^===\s*{re.escape(tag)}\s*===", re.I)
    with open(path, encoding="utf8") as fh:
        for line in fh:
            if pat.match(line):
                break
        else:
            raise ValueError(f"{tag} not found in {path}")


        for header in fh:
            header = header.strip()
            if header:
                header = header.split(',')
                break
        rdr = csv.reader(fh)
        rows = []
        for row in rdr:
            if not row or row[0].startswith('==='):
                break
            rows.append(dict(zip(header, row)))
    if not rows:
        raise ValueError(f"{tag} has no data in {path}")
    return rows


def coord_string(rows, col):
    """'(x,y) (x,y)…' with x = Blocks / n."""
    step = int(rows[0]['Blocks']) - int(rows[1]['Blocks'])
    n    = int(rows[0]['Blocks']) + step - 1
    pairs = [(int(r['Blocks'])/n, float(r[col])) for r in rows]
    return ' '.join(f"({x:.3f},{y})" for x, y in pairs)


def make_block(title, yopts, coords, with_legend):
    """coords = (small, medium, large)"""
    c_small, c_med, c_big = coords
    lines  = f"%================= {title} =========================\n"
    lines += f"\\nextgroupplot[{yopts}]\n"

    lines += indent("\\addplot+[green!70, thin, mark=*, mark options={scale=.7}]"
                    " coordinates {\n"
                    f"  {c_small}\n}};\n", "  ")
    if with_legend:
        lines += indent("\\addlegendentry{small}\n", "  ")

    if c_med:
        lines += indent("\\addplot+[yellow!80!black, thin,"
                        " mark=triangle*, mark options={scale=.7}]"
                        " coordinates {\n"
                        f"  {c_med}\n}};\n", "  ")
        if with_legend:
            lines += indent("\\addlegendentry{medium}\n", "  ")


    if c_big:
        lines += indent("\\addplot+[red!60, thin, mark=square*, mark options={scale=.7}]"
                        " coordinates {\n"
                        f"  {c_big}\n}};\n", "  ")
        if with_legend:
            lines += indent("\\addlegendentry{large}\n", "  ")
    return lines


if len(sys.argv) != 6:
    sys.exit("usage: plot.py <variant> <column> <small> <medium> <large>")

variant, column, f_small, f_med, f_big = sys.argv[1:]
try:
    _, comp = variant.split('_', 1)
except ValueError:
    sys.exit("variant must look like QU_PS, UW_FC, …")

panels = [('QU', 'Quick-Union'),
          ('UW', 'Union-by-Weight'),
          ('UR', 'Union-by-Rank')]

snippet_blocks = []
for idx, (code, title) in enumerate(panels):
    tag     = f"{code}_{comp}"
    coords  = (coord_string(read_section(f_small, tag), column),
               coord_string(read_section(f_med,   tag), column),
               coord_string(read_section(f_big,   tag), column))

    yopts = "title={" + title + "}"
    if code == 'QU':
        yopts += ", ylabel={Normalised $\\mathrm{Cost}$}"
    else:                      
        yopts += ", ylabel={}, ymin=0, ymax=2, ytick={0,1,2}"

    block_text = make_block(title, yopts, coords,
                            with_legend=(idx == 0))
    snippet_blocks.append(block_text)

print('\n'.join(snippet_blocks))
