#include <stdio.h>
#define N 8

short int thingy = 5;

int main() {
  int array[N];
      for (int i=0;i<N;i++){
        printf("%d\n", array[i]); //напечатает сырую память
        *(array+i) = i;
        printf("%d\n", array[i]);
      }


  return 0;
}
