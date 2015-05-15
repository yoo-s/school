#include <iostream>

void fill (int input[], int size) {
   for (int i = 0; i < size; i++) {
      std::cin >> input[i];
      for (int j = 1; j < size-1; j++) {
	 if (input[j] < input[i]){
	   int temp = input[i];
	   input[i] = input[j];
	   input[j] = temp;
	 }
      }
   }
   std::cout << '\n' << std::endl;
}

void merge (int input1[], int input2[], int output[]) {
   int i = 0;
   int j = 0;
   int k = 0;

   while (i < sizeof(input1)/sizeof(input1[0]) && j < sizeof(input2)/sizeof(input2[0])) {
      if (input1[i] <= input2[j]) {
	 output[k] = input1[i];
	 i++;
      }
      else {
	 output[k] = input2[j];
	 j++;
      }
      k++;
   }
}

int main (int argc, char *argv[]) {
   int size = 5;
   int a1[size];
   int a2[size];
   int a3[2*size];

   fill (a1, 5);
   fill (a2, 5);
   merge (a1, a2, a3);

   for (int i = size-1; i >= 0; i--) {
      std::cout << a1[i] << " ";
   }
   for (int i = size-1; i >= 0; i--) {
      std::cout << a2[i] << " ";
   }
   for (int i = 2*size-1; i >= 0; i--) {
      std::cout << a3[i] << " ";
   }
   return 0;
}
