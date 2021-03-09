run     :main.o sub1.o
	 g++ -o run main.o sub1.o

main.o	:main.cpp sub1.h
	 g++ -c main.cpp

sub1.o	:sub1.cpp sub1.h
	 g++ -c sub1.cpp

clean	:
	rm *.o run
