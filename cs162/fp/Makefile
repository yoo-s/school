CXX = g++
SRCS = play.cpp room.cpp
HEADERS = room.hpp
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o play
play.o: play.cpp
	${CXX} -c play.cpp
room.o: room.cpp
	${CXX} -c room.cpp
#roomA.o: roomA.cpp
#	${CXX} -c roomA.cpp
#roomB.o: roomB.cpp
#	${CXX} -c roomB.cpp
#roomC.o: roomC.cpp
#	${CXX} -c roomC.cpp
clean:
	rm -f *.o play

