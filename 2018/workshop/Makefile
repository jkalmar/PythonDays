CC=gcc
CFLAGS=-Wall -Werror -fpic -shared

debug:clean
	$(CC) $(CFLAGS) -g -O0  -o workshop.so workshop.c

stable:clean
	$(CC) $(CFLAGS) -o workshop.so workshop.c

clean:
	rm -vfr *~ workshop.so




