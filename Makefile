main.o : src/main.cpp
	g++ -c main.cpp

room.o : src/room.cpp
	g++ -c room.cpp

all : src/main.o src/room.o
	g++ -o run src/main.o src/room.o

clean:
	rm src/main.o src/room.o run