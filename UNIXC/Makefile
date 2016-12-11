CC = gcc
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS) -Wall
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libuc.a lib/$@
OBJ = $(CC) -c -o lib/$@ $< $(CFLAGS); $(ILIB)
EXE = $(CC) -o bin/$@ src/$@.c $(CFLAGS) -luc

all: doPrntStatic doPrntShared checkEndian checkStrcpy checkStack doLs

libs: prnt.o libprnt.so myendian.o mystr.o mystack.o

prnt.o: src/prnt.c
	$(OBJ)

libprnt.so: src/prnt.c
	$(CC) -shared -fpic -o lib/$@ $< $(CFLAGS)

myendian.o: src/myendian.c
	$(OBJ)

mystr.o: src/mystr.c
	$(OBJ)

mystack.o: src/mystack.c
	$(OBJ)

myls.o: src/myls.c
	$(OBJ)

doPrntStatic: prnt.o
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) -luc

doPrntShared: libprnt.so
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) $(WLFLAGS) -lprnt

checkEndian: myendian.o
	$(EXE)

checkStrcpy: mystr.o
	$(EXE)

checkStack: mystack.o
	$(EXE)

doLs: myls.o
	$(EXE)

.PHONY: clean tests testPrnt testEndian testStr testStack testLs

clean:
	rm -fv lib/* bin/*

tests: testPrnt testEndian testStr testStack testLs

testPrnt:
	bin/doPrntStatic
	@echo
	bin/doPrntShared 9
	@echo
	cd bin && ./doPrntShared 19
	@echo

testEndian:
	bin/checkEndian
	@echo

testStr:
	bin/checkStrcpy
	@echo

testStack:
	bin/checkStack 5 4 3 2 1
	@echo

testLs:
	bin/doLs Makefile && ls -l Makefile
	@echo
	! bin/doLs Makef && ! ls -l Makef
	@echo
	bin/doLs ~/.dmrc && ls -l ~/.dmrc
	@echo
	bin/doLs ~/.cache && ls -dl ~/.cache
