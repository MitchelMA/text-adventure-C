CC := gcc
CFLAGS := -g -Wall -O

source_files := main.o \
LinkedList\linkedlist.o \
Adventure\scene.o \
Adventure\option.o \
extra\clearscreen.o \
extra\input.o

all: $(source_files)
	$(CC) -o main $(CFLAGS) $(source_files)

$(source_files): %.o : %.c

clean:
	del $(source_files)