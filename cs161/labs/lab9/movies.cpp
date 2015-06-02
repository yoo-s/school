#include <iostream>
#include <cstring>

#define NUM_MOVIES 5

struct movie_record {
   std::string title,
	  rating,
	  description,
	  genre;
   int copies;
};

void set_movies(movie_record *mov) {

   for (int i = 0; i < NUM_MOVIES; i++) {
      std::cout << "Movie " << i+1 << ":" << std::endl;
      std::cout << "Title: ";
      std::cin >> mov[i].title;
      std::cout << "Copies: ";
      std::cin >> mov[i].copies;
      std::cout << "Rating: ";
      std::cin >> mov[i].rating;
      std::cout << "Description: ";
      std::cin >> mov[i].description;
      std::cout << "Genre: ";
      std::cin >> mov[i].genre;
      std::cout << std::endl;
   }
}

int which_movies_to_view(movie_record *mov, int choice) {

   std:: cout << "Movies: ";
   for (int i = 0; i < NUM_MOVIES; i++) {
      std::cout << mov[i].title << " ";
   }
   std::cout << std::endl;
   std::cout << "Which movie would you like to view? (1, 2, 3, 4, 5): ";
   std::cin >> choice;

   return choice;
}

void get_movies(movie_record *mov, int choice) {

   std::cout << "You selected the movie " << mov[choice-1].title << "." << std::endl;
   std::cout << std::endl;
}

void get_movie_info(movie_record *mov, int choice) {
  
   std::cout << "Movie info: " << std::endl;
   std::cout << "Title: " << mov[choice-1].title << std::endl;
   std::cout << "Copies: " << mov[choice-1].copies << std::endl;
   std::cout << "Rating: " << mov[choice-1].rating << std::endl;
   std::cout << "Description: " << mov[choice-1].description << std::endl;
   std::cout << "Genre: " << mov[choice-1].genre << std::endl;
   std::cout << std::endl;
}

void rent_movie(movie_record *mov, int choice) {

   mov[choice-1].copies--;
   std::cout << "Renting..." << std::endl;
   std::cout << "Thank you for renting " << mov[choice-1].title << ".\n";
   std::cout << "There are now " << mov[choice-1].copies << " copies left.\n";
}

int main() {

   int choice;

   movie_record mov[NUM_MOVIES];

   set_movies(mov);
   choice = which_movies_to_view(mov, choice);
   get_movies(mov, choice);
   get_movie_info(mov, choice);
   rent_movie(mov, choice);

   return 0;
}
