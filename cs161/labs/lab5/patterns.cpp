#include <iostream>
#include <cstring>

void draw_box(int size);
void draw_top_bottom(int size);
void draw_sides(int size);
void numbers(int size);
void numbers2(int size);
void diamond(int size, char symbol);

int main() {

   int option;
   int size;
   char symbol;

   std::cout << "MENU ------" << std::endl;
   std::cout << "1) Box" << std::endl;
   std::cout << "2) Numbers" << std::endl;
   std::cout << "3) Numbers 2" << std::endl;
   std::cout << "4) Diamond" << std::endl;
   std::cout << std::endl;

   std::cout << "Please select an option: " << std::endl;
   std::cin >> option;

   std::cout << "Enter pattern size: " << std::endl;
   std::cin >> size;

   if (option == 1) {
      draw_box(size);
   } else if (option == 2) {
      numbers(size);
   } else if (option == 3) {
      numbers2(size);
   } else if (option == 4) {
      diamond(size, '*');
   } else {
      std::cout << "Not a valid option, please try again." << std::endl;
   }
   return 0;
}

void draw_box(int size) {

   draw_top_bottom(size);
   draw_sides(size);
   draw_top_bottom(size);
}

void draw_top_bottom(int size) {
   std::cout << "+";
   for (int i = 1; i <= size-2; i++) {
      std::cout << "-";
   }
   std::cout << "+\n";
}

void draw_sides(int size) {
   for (int i = 1; i <= size-2; i++) {
      std::cout << "|";
      for (int i = 1; i <= size-2; i++) {
	 std::cout << " ";
      }
      std::cout << "|\n";
   }
}


void numbers(int size) {

   for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= i; j++) {
	 std::cout << i;
      }
      std::cout << std::endl;
   }
}

void numbers2(int size) {

   for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= i; j++) {
	 std::cout << j;
      }
      std::cout << std::endl;
   }
}

void diamond(int size, char symbol) {
   int stars = 1;

   for (int i = 1; i <= size-(size/2)-1; i++) {
      for (int j = size/2; j >= i; j--) {
	 std::cout << " ";
      }
      for (int j = 0; j < stars; j++) {
	 std::cout << symbol;
      }
      std::cout << std::endl;
      stars += 2;
   }
   stars = size+1;
   for (int i = 1; i <= size-(size/2); i++) {
      for (int j = 0; j < i; j++) {
	 std::cout << " ";
      }
      for (int j = 1; j < stars; j++) {
	 std::cout << symbol;
      }
      std::cout << std::endl;
      stars -= 2;
   }
   /*
      1 - 2 spaces, 1 star
      2 - 1 space, 3 stars
      3 - 0 space, 5 star
      4 - 1 space, 3 stars
      5 - 2 spaces, 1 star
      */
}


