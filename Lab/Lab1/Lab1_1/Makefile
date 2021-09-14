CC=gcc
CFLAGS=-g-Wall
OBJS=Lab1_1.o
TARGET=Lab1_1.out

all:$(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)
	rm -f copy.pdf

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

Lab1_1.o : Lab1_1.c
	$(CC) -c -o Lab1_1.o Lab1_1.c
