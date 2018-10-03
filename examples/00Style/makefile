GPP = g++ -O3 -Wall -std=c++11

A = main.o

Aprog: $A
	$(GPP) -o Aprog $A

main.o: main.h main.cc
	$(GPP) -c main.cc
