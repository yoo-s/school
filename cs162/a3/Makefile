CXX = g++
SRCS = test.cpp char.cpp barbarian.cpp goblin.cpp reptile.cpp bluemen.cpp shadow.cpp
#HEADERS = test.hpp char.hpp barbarian.hpp goblin.hpp reptile.hpp bluemen.hpp shadow.hpp
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o play
test.o: test.cpp
	${CXX} -c test.cpp
char.o: char.cpp
	${CXX} -c char.cpp
barbarian.o: barbarian.cpp
	${CXX} -c barbarian.cpp
goblin.o: goblin.cpp
	${CXX} -c goblin.cpp
reptile.o: reptile.cpp
	${CXX} -c reptile.cpp
bluemen.o: bluemen.cpp
	${CXX} -c bluemen.cpp
shadow.o: shadow.cpp
	${CXX} -c shadow.cpp

clean:
	rm -f *.o play

