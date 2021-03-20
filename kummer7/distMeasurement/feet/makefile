#Kai Yodoya
#CSIS 252 - Assignment 5
#Makefile - prog5

prog5: main.o foot.o
	g++ main.o foot.o -o prog5

main.o: main.cpp foot.h
	g++ -c main.cpp

foot.o: foot.cpp foot.h
	g++ -c foot.cpp

clean:
	rm -rf *.o prog5
