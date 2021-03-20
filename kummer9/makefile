#File: makefile
#Name: Paul Kummer
#Class: CSIS 252
#Program: prog9
#Modified: 11/17/20


EXE = prog9
CC = g++
OBJECTS = main.o Route.o userInChecks.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) Route.h prototypes.h
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp Route.h prototypes.h
									$(CC) $(CFLAGS) -c main.cpp

Route.o:						Route.cpp Route.h prototypes.h
									$(CC) $(CFLAGS) -c Route.cpp

userInChecks.o:					userInChecks.cpp prototypes.h
									$(CC) $(CFLAGS) -c userInChecks.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~

test:							
									$(EXE) < testRoutes.txt