#File: makefile
#Name: Paul Kummer
#Class: CSIS 252
#Program: prog4
#Modified: 10/12/20


EXE = prog5
CC = g++
OBJECTS = main.o LightYear.o printTest.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) LightYear.h prototypes.h
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp LightYear.h prototypes.h
									$(CC) $(CFLAGS) -c main.cpp

LightYear.o:					LightYear.cpp LightYear.h
									$(CC) $(CFLAGS) -c LightYear.cpp

printTest.o:					printTest.cpp prototypes.h LightYear.h
									$(CC) $(CFLAGS) -c printTest.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~
