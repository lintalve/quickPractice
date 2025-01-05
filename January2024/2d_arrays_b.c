#include <stdio.h>
#include <stdlib.h>

#define MATRIX_HEIGHT 4
#define MATRIX_WIDTH 5

//функция которая пойдёт внутрь ниже следующей после этой
void static_array_print(int A[][MATRIX_WIDTH], int N) {  /* матрикс ширь передаётся в виде константы компиляции*/
    for (char i = 0; i < N; i++) {                          /*так передаётся массив как аргумент в функцию*/
        for (char j = 0; j < MATRIX_WIDTH; j++) {           /* ёбаная N передаятся сюда от того, что нельзя через сайзоф получить количество строк*/
        printf("%d\t", A[i][j]);
    }printf("\n");
  }
}


void static_array(char N) {   /* по идее тайп указывается потому, что декларируется функция*/
    int A[N][MATRIX_WIDTH];   /*убрал sizeof, потому, что не вижу в этом смысла.*/
    int x = 1;
    for (char i = 0; i < N; i++) {
        for (char j = 0; j < MATRIX_WIDTH; j++) {
            A[i][j] = x;
            x++;
        }
    }
    static_array_print(A,N);     /*массив передан, как аргутент*//*йобаная N*/
    /*memory investigation*/
    printf("\n Direct memory access:\n");
    for (int* p =(int*)A; p < (int*)A+20; p++) {  /* реаллизован прямой доступ */
        printf("%d  ", *p);                         /* к пямяти через указатели*/
    }
}
//--------------------------------------------------------


int another_array[6][MATRIX_WIDTH];

//void print_arr(int arr[][MATRIX_WIDTH]){     /* синтаксический сахар для int* array,  нельзя из функции печатать размер аррея*/

// this is a very very nice keyboard
//    printf(sizeof(int));
//hell yes this is a nice keyboard
//this is very very very nice keyboard
//alrighty I can type what ever we want
    //for (int i = 0; i < count; i++) {
      /* code */
    //}
//}


//--------------------------------------------------------------------
//--------------------------------------------------------------------
int main(void) {


  for (char i = 0; i < 6; i++) {
      for(char j = 0; j < MATRIX_WIDTH; j++){
        another_array[i][j] = 3;
      }

      printf("\n" );
  }

    char b = 7;
    static_array(b); //аргумент количества строк
    printf(b);
    return 0;
}
