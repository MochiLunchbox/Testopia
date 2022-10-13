all: testopia

testopia: main.o game.o
	g++ main.o game.o -lSDL2 -o bin/testopia

main.o: main.cpp
	g++ main.cpp -c -o main.o

game.o: game.cpp
	g++ game.cpp -c -o game.o
