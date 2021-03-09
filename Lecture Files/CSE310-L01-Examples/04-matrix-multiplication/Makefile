run     :main.o sub2.o
	 g++ -o run main.o sub2.o

main.o	:main.cpp sub2.h
	 g++ -c main.cpp

sub2.o	:sub2.cpp sub2.h
	 g++ -c sub2.cpp

clean	:
	rm *.o run
