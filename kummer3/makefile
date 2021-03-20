// File: makefile
// Name: Paul Kummer
// Class: CSIS 252
// Program: prog3
// Modified: 9/29/20


EXE = prog3
CC = g++
OBJECTS = main.o UnitCompatible.o PopulateArraysFromFile.o PrintUnits.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) constants.h prototypes.h
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp constants.h prototypes.h
									$(CC) $(CFLAGS) -c main.cpp

PopulateArraysFromFile.o:		PopulateArraysFromFile.cpp
									$(CC) $(CFLAGS) -c PopulateArraysFromFile.cpp

PrintUnits.o:					PrintUnits.cpp constants.h
									$(CC) $(CFLAGS) -c PrintUnits.cpp

UnitCompatible.o:				UnitCompatible.cpp constants.h
									$(CC) $(CFLAGS) -c UnitCompatible.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~
