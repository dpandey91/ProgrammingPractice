#Makefile for SLinkedList

CC = g++

CFLAGS = -g -Wall -WeffC++ -o0
LDFLAGS =

EXEC = run

all: clean ${EXEC}


${EXEC}: main.o
	${CC} main.cpp -o ${EXEC}

clean:
	rm -rf ${EXEC}
	rm -rf *.o
	rm -rf *.swp
  
