SHELL = /bin/sh

PROGRAM=test
SOURCEFILES=main.c flexible_queue.c
OBJFILES=$(SOURCEFILES:%.c=%.o)

CFLAGS = -Wall -g
CC = gcc
INCLUDES =
LIBS = -lm

all: $(PROGRAM) valgrind

.SUFFIXES: .c .o

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<

$(PROGRAM): ${OBJFILES}
	${CC} ${CFLAGS} ${INCLUDES} -o $(PROGRAM) ${OBJFILES} ${LIBS}

clean:
	-rm -f *.o $(PROGRAM)

valgrind:
	valgrind --leak-check=full ./$(PROGRAM)
