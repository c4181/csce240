GPP = g++ -O3 -Wall -std=c++11

A = main.o
D = dothework.o
X = xact.o

Aprog: $(A) $(D) $(X)
	$(GPP) -o Aprog $(A) $(D) $(X)

main.o: main.h main.cc
	$(GPP) -c main.cc

dothework.o: dothework.h dothework.cc
	$(GPP) -c dothework.cc

xact.o: xact.h xact.cc
	$(GPP) -c xact.cc
