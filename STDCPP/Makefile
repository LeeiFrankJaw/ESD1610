CC = g++
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS) -Wall
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libstdcpp.a lib/$@
OBJ = $(CC) -c -o lib/$@ $< $(CFLAGS); $(ILIB)
EXE = $(CC) -o bin/$@ src/$@.cpp $(CFLAGS) -lstdcpp

all: countLetter swapCharArr

mystring.o: src/mystring.cpp
	$(OBJ)

countLetter: mystring.o
	$(EXE)

swapCharArr: mystring.o
	$(EXE)

.PHONY: clean tests

clean:
	rm -fv lib/* bin/* tests/out.txt

tests: testCountLetter

testCountLetter:
	test `echo aii233ii | bin/countLetter` -eq 4
	test `bin/countLetter abii1ei` -eq 3

testSwapCharArr:
	bin/swapCharArr < tests/swapCharArr.in.txt > tests/out.txt
	diff -u tests/swapCharArr.out.txt tests/out.txt
	bin/swapCharArr "abc ew" "ew e" > tests/out.txt
	diff -u tests/swapCharArr.out.txt tests/out.txt
