/*********************************************
 ** Program: golife.cpp
 ** Author: Soo-Min Yoo
 ** Date: 06/07/15
 ** Description: Uses arrays, pointers, and structs to run Conway's Game of Life, a standard example of cellular automation.
 ** Input: none
 ** Output: none
 ********************************************/
#include <iostream>

/*********************************************
 ** Struct: Gameboard
 ** Description: Sets up gameboard struct, with height, width, generation counter, and 2D array.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
struct Gameboard {
   public:
      int height;
      int width;
      int gen;
      char board[20][40];
};

const char ON = '*';
const char OFF = '.';

/*********************************************
 ** Function: initBoard
 ** Description: Initializes gameboard
 ** Parameters: Gameboard& b
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
void initBoard (Gameboard& b) {
   for (int i = 0; i < b.height; i++) {
      for (int j = 0; j < b.width; j++) {
	 b.board[i][j] = OFF;
      }
   }
}

/*********************************************
 ** Function: inBoard
 ** Description: Checks if cell being checked is within board boundaries.
 ** Parameters: Gameboard b, int x, int y
 ** Pre-Conditions: none
 ** Post-Conditions: return true or false
 ********************************************/
bool inBoard(Gameboard b, int x, int y) {
   return (y < b.width && x < b.height && y >= 0 && x >= 0);
}

/*********************************************
 ** Function: checkCells
 ** Description: Loops through each cell, determines if it's within boundaries, checks if it fits each rule, and turns it on or off accordingly.
 ** Parameters: Gameboard b
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
void checkCells(Gameboard b) {
   for (int i = 0; i < b.height; i++) {
      for (int j = 0; j < b.width; j++) {
	 //start checking neighbor cells
	 if (inBoard(b, i, j)) {
	    int onCount = 0;
	    for (int k = -1; k <= 1; k++) {
	       for (int m = -1; m <= 1; m++) {
		  if (!(k==0 && m==0) && inBoard(b, i+k, j+m) && b.board[i][j]=='*') {
		     onCount++;
		  }
	       }
	    }	// end checking neighbor cells

	   //	if cell on && 0 or 1 neighbors, cell off
	   //	if cell on && 3+ neighbors, cell off
	   //	if cell off && 3 neighbors, cell on
	    if (b.board[i][j]==ON && (onCount==0 || onCount==1)) {	// rule 1
	       b.board[i][j] = OFF;
	    }
	    else if (b.board[i][j]==ON && (onCount>3)) {		// rule 2
	       b.board[i][j] = OFF;
	    }
	    else if (b.board[i][j]==OFF && (onCount==3)) {		// rule 3
	       b.board[i][j] = ON;
	    }
	    else {
	       b.board[i][j] = b.board[i][j];
	    }
	 }
      }
   }
}

/*********************************************
 ** Function: displayUpdate
 ** Description: Prints updated version of gameboard.
 ** Parameters: Gameboard& f, Gameboard& s, int flip
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
void displayUpdate(Gameboard& f, Gameboard& s, int flip) {
   if (flip == 0) {
      std::cout << "First" << std::endl;
      for (int i = 0; i < f.height; i++) {
	 for (int j = 0; j < f.width; j++) {
	    std::cout << f.board[i][j];
	 }
	 std::cout << std::endl;
      }
   }
   else {
      std::cout << "Second" << std::endl;
      for (int i = 0; i < s.height; i++) {
	 for (int j = 0; j < s.width; j++) {
	    std::cout << s.board[i][j];
	 }
	 std::cout << std::endl;
      }
   }
}

/*********************************************
 ** Function: main
 ** Description: Sets up instances of gameboard struct, asks user input for board dimensions and pattern choice, initializes gameboards, checks each cell and prints updated cells in gameboard while switching between the two gameboards to keep births and deaths instantaneous.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: return 0
 ********************************************/
int main() {
   Gameboard first, second;
   int flip = 0;	//switches to other array
   int choice;
   bool game = true;


   //needs 2D dynamic array for specifying h and w
   std::cout << "Height: ";
   std::cin >> first.height;
   second.height = first.height;
   std::cout << std::endl;
   std::cout << "Width: ";
   std::cin >> first.width;
   second.width = first.width;
   std::cout << std::endl;

   //menu giving choice of pattern
   std::cout << "Menu ---------------" << std::endl;
   std::cout << "Pick a pattern (1, 2, 3): " << std::endl;
   std::cout << "1) Oscillator" << std::endl;
   std::cout << "2) Glider" << std::endl;
   std::cout << "3) Glider gun" << std::endl;
   std::cin >> choice;

   initBoard(first);
   initBoard(second);
   
   if (choice == 1) {				// Oscillator option
      //starting position (fixed) for testing
      first.board[3][4] = ON;
      first.board[3][5] = ON;
      first.board[3][6] = ON;
   }

   int count = 0;
   while (game) {
      displayUpdate(first, second, flip);
      if (flip == 0) {				// check and update first board
	 checkCells(first);
	 displayUpdate(first, second, flip);
	 initBoard(first);
      }
      else {					// check and update second board
	 checkCells(second);
	 displayUpdate(first, second, flip);
	 initBoard(second);
      }
      flip = 1-flip;				// switch to other board
      count++;
      if (count == 3) {		// if reach certain max count, stop game
	 game = false;
      }
   }

   return 0;
}

