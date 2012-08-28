This is the README of the of coal.

Here is the current class tree, it was generated with the command
`py-utils/hierarchy.py | dot -Tpng -Gstyle=filled -Ncolor=white -Nstyle=filled -Nshape=box -Gsplines=ortho -Estyle=dashed -Gfontname="Droid Sans Mono" -Nfontname="Droid Sans" > classes.png`

![Alt text](https://github.com/crypt3lx2k/coal/raw/master/classes.png)

Work in progress.

- Testing facilities.
- Actual tests.
- Parallel traversal of test graph (parallel DAG implementation?).
- Thread local cleanup function stack when threads die, must be exception safe.
- Possibility for setting error handlers that are called when exceptions are thrown instead of try-catch macros. (Call only when thread stack is empty for try handlers? Design interface like signal(3)?)
