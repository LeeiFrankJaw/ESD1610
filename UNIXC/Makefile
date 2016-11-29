CC = gcc

libs: prnt.o libprnt.so endian.o

prnt.o: src/prnt.c
	$(CC) -c -o lib/$@ $<

libprnt.so: src/prnt.c
	$(CC) -shared -fpic -s -o lib/$@ $<
	ln -f lib/$@ bin/$@

endian.o: src/endian.c
	$(CC) -c -o lib/$@ $<

doPrntStatic: prnt.o
	$(CC) -s -o bin/$@ src/doPrnt.c lib/prnt.o

doPrntShared: libprnt.so
	$(CC) -s -o bin/$@ src/doPrnt.c lib/libprnt.so

checkEndian: endian.o
	$(CC) -s -o bin/$@ src/$@.c lib/$<

install: doPrntStatic doPrntShared checkEndian

.PHONY: clean

clean:
	rm -fv lib/* bin/*
