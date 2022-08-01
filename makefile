CC := gcc
CFLAGS := -g 

source_files := main.o \
LinkedList\linkedlist.o \
DoubleLinkedList\doubleLinkedList.o \
Adventure\adventure.o \
extra\clearscreen.o \
extra\input.o \
Story\story.o

all: $(source_files)
	$(CC) -o main $(CFLAGS) $(source_files)

$(source_files): %.o : %.c

clean:
	del $(source_files)