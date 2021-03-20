#File: makefile
#Name: Paul Kummer
#Class: CSIS 252
#Program: prog8
#Modified: 11/12/20


EXE = prog8
CC = g++
OBJECTS = main.o mailStack.o mainFunctions.o mailQueue.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) mailQueue.h mailStack.h prototypes.h constants.h	
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp mailQueue.h prototypes.h mailStack.h
									$(CC) $(CFLAGS) -c main.cpp

mailStack.o:					mailStack.cpp mailStack.h
									$(CC) $(CFLAGS) -c mailStack.cpp

mainFunctions.o:				mainFunctions.cpp prototypes.h
									$(CC) $(CFLAGS) -c mainFunctions.cpp

mailQueue.o:					mailQueue.cpp mailQueue.h constants.h
									$(CC) $(CFLAGS) -c mailQueue.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~
