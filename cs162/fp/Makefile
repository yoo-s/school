CXX = g++
SRCS = play.cpp inv.cpp room.cpp item.cpp piano.cpp study.cpp kitchen.cpp foyer.cpp secret.cpp
pr1: ${SRCS}
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
kitchen.o: kitchen.cpp
#	${CXX} -c kitchen.cpp
foyer.o: foyer.cpp
	${CXX} -c foyer.cpp
secret.o: secret.cpp
	${CXX} -c secret.cpp
item.o: item.cpp
	${CXX} -c item.cpp
clean:
	rm -f *.o play

