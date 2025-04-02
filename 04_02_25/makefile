all: main.cpp drink course room
	g++ -pedantic-errors -g  -fdiagnostics-color=always main.cpp drink course room -o main
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always drink.cpp -o drink 
course: course.h course.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always course.cpp -o course
room: room.h room.cpp
	g++ -pedantic-errors -g -c -fdiagnostics-color=always room.cpp -o room