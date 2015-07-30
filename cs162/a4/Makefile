CXX = g++
SRCS = lineup.cpp losers.cpp tournament.cpp
HEADERS = lineup.hpp losers.hpp tournament.hpp
pr1: ${SRCS} ${HEADERS}
	${CXX} ${SRCS} -o play
lineup.o: lineup.cpp
	${CXX} -c lineup.cpp
losers.o: losers.cpp
	${CXX} -c losers.cpp
tournament.o: tournament.cpp
	${CXX} -c tournament.cpp
clean:
	rm -f *.o play

