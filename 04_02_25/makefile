all: main.cpp drink course room drinkOrder
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp drink course room drinkOrder -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drink.cpp -o drink 
drinkOrder: drinkOrder.h drinkOrder.cpp 
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drinkOrder.cpp -o drinkOrder
course: course.h course.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always course.cpp -o course
room: room.h room.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always room.cpp -o room