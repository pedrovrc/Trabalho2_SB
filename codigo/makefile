# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
main: main.o preprocessamento.o tradutor.o
	$(CC) $(CFLAGS) -o tradutor main.o preprocessamento.o tradutor.o

main.o: main.cpp preprocessamento.h tradutor.h
	$(CC) $(CFLAGS) -c main.cpp

preprocessamento.o: preprocessamento.h
	$(CC) $(CFLAGS) -c preprocessamento.cpp preprocessamento.h

tradutor.o: tradutor.h
	$(CC) $(CFLAGS) -c tradutor.cpp tradutor.h

clean:
	$(RM) $main