run     :main.o sub1.o sub2.o sub3.o
	 g++ -o run main.o sub1.o sub2.o sub3.o

main.o	:main.cpp sub1.h sub2.h sub3.h
	 g++ -c main.cpp

sub1.o	:sub1.cpp sub1.h
	 g++ -c sub1.cpp

sub2.o	:sub2.cpp sub2.h
	 g++ -c sub2.cpp

sub3.o  :sub3.cpp sub3.h
	 g++ -c sub3.cpp

clean	:
	rm *.o run
