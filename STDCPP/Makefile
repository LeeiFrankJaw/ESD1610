CC = g++
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS) -Wall
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libstdcpp.a lib/$@
OBJ = $(CC) -c -o lib/$@ $< $(CFLAGS); $(ILIB)
EXE = $(CC) -o bin/$@ src/$@.cpp $(CFLAGS) -lstdcpp

all:

countLetterAux.o: src/countLetterAux.cpp
	$(OBJ)

countLetter: countLetterAux.o
	$(EXE)

.PHONY: clean tests

clean:
	rm -fv lib/* bin/*

tests:
