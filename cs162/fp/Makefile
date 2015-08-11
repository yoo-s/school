CXX = g++
SRCS = play.cpp inv.cpp room.cpp item.cpp piano.cpp study.cpp
HEADERS = inv.hpp room.hpp item.hpp piano.hpp study.hpp
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o play
play.o: play.cpp
	${CXX} -c play.cpp
inv.o: inv.cpp
	${CXX} -c inv.cpp
room.o: room.cpp
	${CXX} -c room.cpp
piano.o: piano.cpp
	${CXX} -c piano.cpp
study.o: study.cpp
	${CXX} -c study.cpp
#roomC.o: roomC.cpp
#	${CXX} -c roomC.cpp
item.o: item.cpp
	${CXX} -c item.cpp
clean:
	rm -f *.o play

