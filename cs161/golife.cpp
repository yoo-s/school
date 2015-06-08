#include <iostream>

struct Gameboard {
   public:
      int height;
      int width;
      int gen;
      char board[20][40];
};

const char ON = '*';
const char OFF = '.';

void initBoard (Gameboard& b) {
   for (int i = 0; i < b.height; i++) {
      for (int j = 0; j < b.width; j++) {
	 b.board[i][j] = OFF;
      }
   }
}

void displayUpdate(Gameboard& b) {
   for (int i = 0; i < b.height; i++) {
      for (int j = 0; j < b.width; j++) {
	 std::cout << b.board[i][j];
      }
      std::cout << std::endl;
   }
}

int main() {
   Gameboard first, second;
   int flip = 0;	//switches to other array
   int choice;


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

   char board[20][40];
   initBoard(first);

   //starting position (fixed)


   displayUpdate(first);


   return 0;
}



   //prompt for and check user input
   //flip between 2 2d arrays, updating, use 0/1
   //for loop check each cell, if statements checking neighbor cells
   //	if cell on && 0 or 1 neighbors, cell off
   //	if cell on && 3+ neighbors, cell off
   //	if cell off && 3 neighbors, cell on
   //display updated array to screen
   //clear and flip to other array

