#include <iostream>


bool is_equal (char **str1, char **str2) {
   int i;
   for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
      if (str1[i] != str2[i]) {
	 return false;
      }
   }
   if (str1[i] != '\0' || str2[i] != '\0') {
      return false;
   }
   return true;
}

int main (int argc, char *argv[]) {
   if (argc >= 3) {
      std::cout << is_equal(&argv[1], &argv[2]) << std::endl;
   }

   return 0;
}
