all: clockexcept clock main.cpp
	g++ -pedantic-errors -g main.cpp clock clockexcept -o main
clock: clock.h clock.cpp
	g++ -pedantic-errors -g -c clock.cpp -o clock
clockexcept: clockExcept.h clockExcept.cpp
	g++ -pedantic-errors -g -c clockExcept.cpp -o clockexcept
