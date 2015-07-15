CXX = g++
SRCS = main.cpp dice.cpp loadeddice.cpp
HEADERS = 
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o dice
main.o: main.cpp
	${CXX} -c main.cpp
dice.o: dice.cpp
	${CXX} -c dice.cpp
loadeddice.o: loadeddice.cpp
	${CXX} -c loadeddice.cpp
clean:
	rm -f *.o dice

