cc=gcc -g
bin=./bin
inc=./include
lib=./lib
src=./src
cflags=-Wall -I$(inc) -c
exefile=$(bin)/tarsau

all: $(exefile)
	$(cc) $(lib)/*.o -o $(exefile)


run: all
	clear
	$(exefile)


$(exefile): birlestir parcala parametreIsle
	$(cc) $(cflags) $(src)/main.c -o $(lib)/main.o


birlestir:
	$(cc) $(cflags) $(src)/birlestir.c -o $(lib)/birlestir.o


parcala:
	$(cc) $(cflags) $(src)/parcala.c -o $(lib)/parcala.o


parametreIsle:
	$(cc) $(cflags) $(src)/parametreIsle.c -o $(lib)/parametreIsle.o


clean:
	rm $(lib)/* $(bin)/*
