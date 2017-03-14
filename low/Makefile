.PHONY: all clean

all: html

html: Doxyfile low.h
	doxygen $<

Doxyfile-diff:
	diff Doxyfile.ref Doxyfile || true

clean:
	rm -rf html
	rm -f doxygen.tag
