main.o : main.cpp
	g++ -c main.cpp

room.o : room.cpp
	g++ -c room.cpp

all : main.o room.o
	g++ -o run main.o room.o

clean:
	rm main.o room.o run

clr:
	rm run