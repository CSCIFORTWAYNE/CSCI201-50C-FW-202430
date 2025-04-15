all: drink clock main.cpp
	g++ -pedantic-errors -g main.cpp clock drink -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -c clock.cpp -o clock
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c drink.cpp -o drink