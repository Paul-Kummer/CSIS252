#File: makefile
#Name: Paul Kummer
#Class: CSIS 252
#Program: prog6
#Modified: 10/24/20


EXE = prog6
CC = g++
OBJECTS = main.o UnitCompatible.o PopulateArraysFromFile.o PrintUnits.o Measurment.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) constants.h prototypes.h Measurment.h
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp constants.h prototypes.h Measurment.h
									$(CC) $(CFLAGS) -c main.cpp

PopulateArraysFromFile.o:		PopulateArraysFromFile.cpp Measurment.h
									$(CC) $(CFLAGS) -c PopulateArraysFromFile.cpp

PrintUnits.o:					PrintUnits.cpp constants.h Measurment.h
									$(CC) $(CFLAGS) -c PrintUnits.cpp

UnitCompatible.o:				UnitCompatible.cpp constants.h Measurment.h
									$(CC) $(CFLAGS) -c UnitCompatible.cpp

Measurment.o:					Measurment.cpp Measurment.h
									$(CC) $(CFLAGS) -c Measurment.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~
