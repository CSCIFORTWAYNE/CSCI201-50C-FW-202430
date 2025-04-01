all: main.cpp drink
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp drink -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drink.cpp -o drink 