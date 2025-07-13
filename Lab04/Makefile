# Makefile for Two-Dice Pig game
CC = g++

CFLAGS = -Wall -std=c++11

test_die: die.o die_test.o
	$(CC) $(CFLAGS) -o die_test die.o die_test.o

lab04: die.o lab04.o
	$(CC) $(CFLAGS) -o lab04 die.o lab04.o

die.o: die.cpp die.hpp
	$(CC) $(CFLAGS) -c die.cpp

die_test.o: die_test.cpp die.hpp
	$(CC) $(CFLAGS) -c die_test.cpp

lab04.o: lab04.cpp die.hpp
	$(CC) $(CFLAGS) -c lab04.cpp

clean:
	rm *.o
