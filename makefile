# Author: Ryan Peters
# Date: 11/07/15
# Description: makefile for creatures battle 
all:
	g++ Goblin.cpp Barbarian.cpp Reptile.cpp Bluemen.cpp Shadow.cpp Die.cpp main.cpp -o CreatureMain
	
clean: 
	rm *.o a.out a.exe