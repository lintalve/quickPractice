#include <stdio.h>



int main(void) {

  char a = 7;
  char array[a];
  for (char i = 0; i < a; i++) {
    array[i] = i;
    printf("%d", array[i]);
  }
/////---------------------------------------------------
//void print_size(a) {
  /* code */
//}
  char* return_array(char a[]){
    return a;
  }
  char* pt = return_array(array);

  void print_ar_by_pointer(char* p) {
    printf("\n%d\n", *p);
    printf("%d\n", *p+1);
    for (int i = 0; i < 12; i++) { //перевалив за длину массива на экран
      printf("%d\n", *(p+i));      //выыводится мусор в незабитых в массив
    }                               //ячеек
  }

  print_ar_by_pointer(pt);

   //printf("\n%p\n", pt);
   //printf("%d\n", pt);



  return 0;
}
