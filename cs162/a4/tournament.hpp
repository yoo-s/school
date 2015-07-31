#ifndef TOURNAMENT_HPP_
#define TOURNAMENT_HPP_

#include <iostream>
#include <queue>
#include <stack>
#include "tournament.cpp"

/*********************************************
 ** Function: round
 ** Description: runs a competition round between two players
 ** Parameters: Lineup &line1, Lineup &line2, Losers &pile, int &s1, int &s2
 ********************************************/
void round(Lineup &line1, Lineup &line2, Losers &pile, int &s1, int &s2);

#endif /* TOURNAMENT_HPP_ */
