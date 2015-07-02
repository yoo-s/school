CXX = g++
SRCS = main.cpp average.cpp summation.cpp
HEADERS = average.h summation.h
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o pr1
main.o: main.cpp
	${CXX} -c main.cpp
average.o: average.cpp
	${CXX} -c average.cpp
summation.o: summation.cpp
	${CXX} -c summation.cpp
clean:
	rm -f *.o pr1

