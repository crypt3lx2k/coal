This is the README of the of coal.

Here is the current class tree, it was generated with the command
`py-utils/hierarchy.py | dot -Tpng -Gstyle=filled -Ncolor=white -Nstyle=filled -Nshape=box -Gsplines=ortho -Estyle=dashed -Gfontname="Droid Sans Mono" -Nfontname="Droid Sans" > classes.png`

![Alt text](https://github.com/crypt3lx2k/coal/raw/master/classes.png)

Major points are,
- Namespace pollutions cause function-like and not object-like macros to be
defined for functions.
So it's safe to name variables things like 'object' and 'thread'.

- All classes start with an uppercase letter, just like in Java.
As to avoid collision between names of methods and names of classes, even
after namespace pollution what is a method and what is a class becomes
unambiguous.

- Before namespace pollution every identifier should start with either
coal, Coal or COAL followed by an underscore character.
This is to give the user greater freedom in defining things, easier
to expect non-collision.

- A saner naming scheme, possibly rename lang as this isn't a language,
possibly rename core to something that reflects its nature as
private implementation details.
This is to make the library more intuitive to use.

- Stop using abbreviations in names.
It's better to offer namespace pollution than it is to use bad names, this
will improve clarity and make the library more intuitive to use.

- Rewrite utility_stack to make it safer.
As it stands allocation errors in the exception handling system might cause
a segmentation fault. It's better to throw an unhandled exception than it
is to segfault.

- Move away from using a #define for the var definition.
Using a #define with var causes multiple declarations on one line to fail,
it's better to use two typedefs than it is to use a #define even though it
makes const behave nicely.

- Provide test facilities, so making changes to existing code is less likely
to cause errors.
