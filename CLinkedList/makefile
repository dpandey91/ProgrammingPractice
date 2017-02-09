#Makefile for CLinkedList

CC = g++

CFLAGS = -g -W -Weffc++ -Wall -o0
LDFLAGS =


EXEC = run
EXEC2 = run2

all: clean ${EXEC} ${EXEC2}

${EXEC}: main.o
	${CC} main.cpp -o ${EXEC}
	${CC} main-char.cpp -o ${EXEC2}

clean:
	rm -rf ${EXEC}
	rm -rf ${EXEC2}
	rm -rf *.o
	rm -rf *.swp

