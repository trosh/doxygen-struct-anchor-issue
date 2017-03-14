.PHONY: all low.doc high.doc clean Doxyfile-diff

all: low/html high/html

low.doc:
	make -C low

low/html: low.doc
low/doxygen.tag: low.doc

high.doc: low/doxygen.tag
	make -C high

high/html: high.doc

clean:
	make -C low  $@
	make -C high $@

Doxyfile-diff:
	make -C low  $@
	make -C high $@
