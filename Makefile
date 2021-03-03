CC = gcc
CFLAGS = -o build/walker
all: walker

walker:
	mkdir -p build;
	$(CC) ./utils/*.c  walk.c $(CFLAGS);

install:
	cp build/walker /bin/walker;
	chmod 777 /bin/walker;

