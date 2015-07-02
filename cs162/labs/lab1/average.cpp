#include "average.h"

double avg(const double *p, int size) {
   double sum = 0;
   double avg;

   for (int i = 0; i < size; i++) {
      sum = sum + p[i];
   }
   avg = sum/size;
   return avg;
}
