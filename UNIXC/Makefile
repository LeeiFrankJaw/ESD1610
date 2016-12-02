CC = gcc
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS)
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libuc.a lib/$@
OBJ = $(CC) -c -o lib/$@ $< $(CFLAGS); $(ILIB)
EXE = $(CC) -o bin/$@ src/$@.c $(CFLAGS) -luc

libs: prnt.o libprnt.so hw.o

prnt.o: src/prnt.c
	$(OBJ)

libprnt.so: src/prnt.c
	$(CC) -shared -fpic -o lib/$@ $< $(CFLAGS)

hw.o: src/hw.c
	$(OBJ)

doPrntStatic: prnt.o
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) -luc

doPrntShared: libprnt.so
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) $(WLFLAGS) -lprnt

checkEndian: hw.o
	$(EXE)

checkStrcpy: hw.o
	$(EXE)

install: doPrntStatic doPrntShared checkEndian checkStrcpy

.PHONY: clean

clean:
	rm -fv lib/* bin/*
