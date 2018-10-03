GPP = g++ -O3 -Wall -std=c++11

M = main.o

Aprog: $(M)
	$(GPP) -o Aprog $(M)

main.o: main.h main.cc # recompile if EITHER file changes
#	$(GPP) -o main.o -c main.cc
	$(GPP) -DWHATEVER -o main.o -c main.cc
clean:
	rm Aprog
	clean

