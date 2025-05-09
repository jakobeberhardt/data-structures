#!/usr/bin/env python3

import sys, csv, re

# ---------------------------------- description helpers -----
UNION_NAMES = {
    'QU': 'Quick Union',
    'UW': 'Union-by-Weight',
    'UR': 'Union-by-Rank',
}
COMP_NAMES = {
    'NC': 'No Compression',
    'FC': 'Full Compression',
    'PS': 'Path Splitting',
    'PH': 'Path Halving',
}

def nice_caption(tag):
    try:
        union, comp = tag.split('_')
        return f"{UNION_NAMES[union]} with {COMP_NAMES[comp]}"
    except Exception:
        return tag       # fallback – should never trigger


# ---------------------------------- block reader ------------
TAG_RE = re.compile(r'^===\s*([A-Z]+_[A-Z]+)\s*===\s*$')

def blocks(path):
    """Yield (tag, header list, rows list) for every === TAG === section."""
    with open(path, encoding='utf8') as fh:
        while True:
            # ---- seek next tag line
            for line in fh:
                m = TAG_RE.match(line)
                if m:
                    tag = m.group(1)
                    break
            else:
                return                      # EOF

            # ---- read header = first non-blank line
            for header in fh:
                header = header.strip()
                if header:
                    cols = header.split(',')
                    break
            rows = []
            rdr = csv.reader(fh)
            for row in rdr:
                if not row or row[0].startswith('==='):
                    # rewind one step so the outer loop sees this tag
                    if row and row[0].startswith('==='):
                        fh.seek(fh.tell() - len(','.join(row)) - 1)
                    break
                rows.append(row)
            yield tag, cols, rows


# ---------------------------------- LaTeX writer ------------
def latex_table(tag, cols, rows):
    # choose a numeric column format for every field
    col_types = ['S' if re.fullmatch(r'-?\d+(\.\d+)?([eE][+-]?\d+)?', r)
                          else 'l'
                 for r in rows[0]]
    fmt = ' '.join(col_types)
    caption = nice_caption(tag)

    lines = []
    lines.append(r'\begin{table}[H]')
    lines.append(r'  \centering')
    lines.append(f'  \\caption{{{caption}}}')
    lines.append(f'  \\label{{tab:{tag}}}')
    lines.append(f'  \\begin{{tabular}}{{{fmt}}}')
    lines.append(r'    \toprule')
    lines.append('    ' + ' & '.join(cols) + r' \\')
    lines.append(r'    \midrule')
    for row in rows:
        lines.append('    ' + ' & '.join(row) + r' \\')
    lines.append(r'    \bottomrule')
    lines.append(r'  \end{tabular}')
    lines.append(r'\end{table}')
    return '\n'.join(lines)


# ---------------------------------- main --------------------
if len(sys.argv) != 2:
    sys.exit("usage: make_tables.py  <csv-file>")

for tag, cols, rows in blocks(sys.argv[1]):
    print(latex_table(tag, cols, rows))
    print('\n')   # blank line between tables
