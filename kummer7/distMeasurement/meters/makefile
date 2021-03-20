#Spencer Meyer
#CSIS 252 - Assignment 5
#Makefile - prog5

prog5: main.o meter.o
	g++ main.o meter.o -o prog5

main.o: main.cpp meter.h
	g++ -c main.cpp

meter.o: meter.cpp meter.h
	g++ -c meter.cpp

clean:
	rm -rf *.o prog5
