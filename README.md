This is a pair of fake C projects, *low* and *high*,
with *high* depending on *low*.
They each have a header file, which has a typedef
to a struct and a typedef to a pointer to that
(all of this documented).

    /** ... */
    typedef struct {...} OBJECT_s;
    /** ... */
    typedef OBJECT_s * OBJECT_p;

That is not necessarily a practice I particularly condone,
but valid C nontheless.

Doxyfiles and Makefiles have been provided to generate
the documentation and tagfile for *low*,
and the documentation for *high* using *low*'s tagfile.

A simple call to `make` in this repo's root
will make both docs, and should hopefully reproduce
the warning I am trying to understand / avoid / fix
when building the *high* doc.

    low/doxygen.tag:26: warning: Unexpected tag `anchor' found

The mentioned line is the following:

    23  <compound kind="struct">
    24    <name>object</name>
    25    <filename>low_8h.html</filename>
    26    <anchor>structobject</anchor>    <!-- CULPRIT LINE -->
    27    <member kind="variable">
    28      <type>int</type>
    29      <name>val</name>
    30      <anchorfile>low_8h.html</anchorfile>

To see how the Doxyfiles were made,
I included references (made with `doxygen -g`)
and the differences can be displayed with a simple call
to `make Doxyfile-diff` which will call `diff`
in both projects.

For info, these are the relevant changes at the time
of writing this :

    make -C low  Doxyfile-diff

    > INLINE_SIMPLE_STRUCTS  = YES
    > INPUT                  = .
    > GENERATE_LATEX         = NO
    > GENERATE_TAGFILE       = doxygen.tag

    make -C high Doxyfile-diff

    > INPUT                  = .
    > GENERATE_LATEX         = NO
    > TAGFILES               = ../low/doxygen.tag=../../low/html
