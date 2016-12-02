CC = gcc
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS)
WLFLAGS = -Wl,-rpath,$(PWD)/lib
ILIB = ar r lib/libuc.a lib/$@

libs: prnt.o libprnt.so endian.o

prnt.o: src/prnt.c
	$(CC) -c -o lib/$@ $< $(CFLAGS)
	$(ILIB)

libprnt.so: src/prnt.c
	$(CC) -shared -fpic -o lib/$@ $< $(CFLAGS)

hw.o: src/hw.c
	$(CC) -c -o lib/$@ $< $(CFLAGS)
	$(ILIB)

doPrntStatic: prnt.o
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) -luc

doPrntShared: libprnt.so
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) $(WLFLAGS) -lprnt

checkEndian: hw.o
	$(CC) -o bin/$@ src/$@.c $(CFLAGS) -luc

install: doPrntStatic doPrntShared checkEndian

.PHONY: clean

clean:
	rm -fv lib/* bin/*
