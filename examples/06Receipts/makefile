GPP = g++ -O3 -Wall -std=c++11

A = main.o
D = dothework.o

Aprog: $(A) $(D)
	$(GPP) -o Aprog $(A) $(D)

main.o: main.h main.cc
	$(GPP) -c main.cc

dothework.o: dothework.h dothework.cc
	$(GPP) -c dothework.cc
