CC = g++
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS) -Wall
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libstdcpp.a lib/$@
OBJ = $(CC) -c -o lib/$@ $< $(CFLAGS); $(ILIB)
EXE = $(CC) -o bin/$@ src/$@.cpp $(CFLAGS) -lstdcpp

all: countLetter

mystring.o: src/mystring.cpp
	$(OBJ)

countLetter: mystring.o
	$(EXE)

.PHONY: clean tests

clean:
	rm -fv lib/* bin/*

tests: testCountLetter

testCountLetter:
	test `echo aii233ii | bin/countLetter` -eq 4
	test `bin/countLetter abii1ei` -eq 3
