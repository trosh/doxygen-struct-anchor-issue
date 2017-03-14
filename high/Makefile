.PHONY: all doc clean Doxyfile-diff

all: html doxygen.tag

doc: Doxyfile high.h
	doxygen $<

html: doc

doxygen.tag: doc

Doxyfile-diff:
	diff Doxyfile.ref Doxyfile || true

clean:
	rm -rf html
