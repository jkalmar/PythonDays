CC=gcc
CFLAGS=-Wall -Werror -fpic -shared

debug:clean
	$(CC) $(CFLAGS) -g -O0  -o example.so example.c

stable:clean
	$(CC) $(CFLAGS) -o example.so example.c

clean:
	rm -vfr *~ example.so




