#File: makefile
#Name: Paul Kummer
#Class: CSIS 252
#Program: prog7
#Modified: 10/31/20


EXE = prog7
CC = g++
OBJECTS = main.o meter.o foot.o distMeasurement.o unitTestTemplate.o
LFLAGS =
CFLAGS =

$(EXE):							$(OBJECTS) distMeasurement/meters/meter.h distMeasurement/feet/foot.h distMeasurement/distMeasurement.h
									$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:							main.cpp distMeasurement/meters/meter.h distMeasurement/feet/foot.h distMeasurement/distMeasurement.h
									$(CC) $(CFLAGS) -c main.cpp

meter.o:						distMeasurement/meters/meter.cpp distMeasurement/meters/meter.h distMeasurement/distMeasurement.h
									$(CC) $(CFLAGS) -c distMeasurement/meters/meter.cpp

foot.o:							distMeasurement/feet/foot.cpp distMeasurement/feet/foot.h distMeasurement/distMeasurement.h
									$(CC) $(CFLAGS) -c distMeasurement/feet/foot.cpp

distMeasurement.o:				distMeasurement/distMeasurement.cpp distMeasurement/distMeasurement.h
									$(CC) $(CFLAGS) -c distMeasurement/distMeasurement.cpp

unitTestTemplate.o:				unitTestTemplate.cpp distMeasurement/meters/meter.h distMeasurement/feet/foot.h
									$(CC) $(CFLAGS) -c unitTestTemplate.cpp

clean:
									rm -rf $(EXE) $(OBJECTS) *~
