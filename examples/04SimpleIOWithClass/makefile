GPP = g++ -O3 -Wall -std=c++11

M = main.o
D = dothework.o

Aprog: $(M) $(D)
	$(GPP) -o Aprog $(M) $(D)

main.o: main.h main.cc
	$(GPP) -o main.o -c main.cc

dothework.o: dothework.h dothework.cc
	$(GPP) -o dothework.o -c dothework.cc

clean:
	rm Aprog
	clean

