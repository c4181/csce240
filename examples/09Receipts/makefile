GPP = g++ -O3 -Wall -std=c++11

UTILS = ../../Utilities

A = main.o
D = dothework.o
X = xact.o
U = utils.o

Aprog: $(A) $(D) $(X) $(U)
	$(GPP) -o Aprog $(A) $(D) $(X) $(U)

main.o: main.h main.cc
	$(GPP) -c main.cc

dothework.o: dothework.h dothework.cc
	$(GPP) -c dothework.cc

xact.o: xact.h xact.cc
	$(GPP) -c xact.cc

utils.o: $(UTILS)/utils.h $(UTILS)/utils.cc
	$(GPP) -c $(UTILS)/utils.cc
