CC = gcc
IFLAGS = -Iinclude
LFLAGS = -Llib
CFLAGS = -s $(IFLAGS) $(LFLAGS)
WLFLAGS = -Wl,-rpath,$(PWD)/bin
ILIB = ar r lib/libuc.a lib/$@

libs: prnt.o libprnt.so endian.o

prnt.o: src/prnt.c
	$(CC) -c -o lib/$@ $< $(CFLAGS)
	$(ILIB)

libprnt.so: src/prnt.c
	$(CC) -shared -fpic -o bin/$@ $< $(CFLAGS)

myendian.o: src/myendian.c
	$(CC) -c -o lib/$@ $< $(CFLAGS)
	$(ILIB)

doPrntStatic: prnt.o
	$(CC) -o bin/$@ src/doPrnt.c $(CFLAGS) -luc

doPrntShared: libprnt.so
	$(CC) -o bin/$@ src/doPrnt.c bin/$< $(CFLAGS) $(WLFLAGS)

checkEndian: myendian.o
	$(CC) -o bin/$@ src/$@.c $(CFLAGS) -luc

winstall: doPrntStatic doPrntShared checkEndian

install: doPrntStatic doPrntShared checkEndian

.PHONY: clean

clean:
	rm -fv lib/* bin/*
