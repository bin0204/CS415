all: vendingmachine

vendingmachine:	dispenser.o item.o main.o
	g++ dispenser.o item.o main.o -o vendingmachine

main.o: main.cpp
	g++ -c main.cpp

dispenser.o: dispenser.cpp dispenser.h
	g++ dispenser.cpp -c

item.o: item.cpp item.h dispenser.h
	g++ item.cpp -c

clean:
	rm -f *.o
