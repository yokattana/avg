CFLAGS += -ansi -Wall
LDLIBS += -lm

prefix ?= /usr
BINDIR ?= $(prefix)/bin
MANDIR ?= $(prefix)/share/man/man1

.PHONY: all clean distclean install uninstall

all: avg Readme.txt

Readme.txt: avg.1
	groff -mdoc -Tascii avg.1 | col -bx > Readme.txt

clean:
	$(RM) avg
	$(RM) avg.exe

distclean: clean
	rm -f Readme.txt

install: avg avg.1
	install avg $(BINDIR)/
	install avg.1 $(MANDIR)/

uninstall:
	$(RM) $(BINDIR)/avg
	$(RM) $(MANDIR)/avg.1
