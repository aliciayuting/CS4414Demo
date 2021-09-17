CFLAGS  = -std=c++17 -O3 -Wall

output: main.o numberQueue.o 
	g++ $(CFLAGS) main.o numberQueue.o -o output

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

numberQueue.o: numberQueue.cpp numberQueue.h
	g++ $(CFLAGS) -c numberQueue.cpp

clear:
	rm *.o output