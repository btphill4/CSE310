# Copyright: Guoliang XUe
# Last updated on 2021-0112
# This is an example for a Makefile
# Please pay attention to the tab
run     :main.o sub1.o sub2.o
	 g++ -o run main.o sub1.o sub2.o

main.o	:main.cpp sub1.h sub2.h
	 g++ -c main.cpp

sub1.o	:sub1.cpp sub1.h
	 g++ -c sub1.cpp

sub2.o	:sub2.cpp sub2.h
	 g++ -c sub2.cpp

clean	:
	rm *.o run
