#include<stdio.h>

///указатель это имя адреса
int main(void) {
  int i = 8;
  int* pi = &i;  //int* тип данных, типа url(в данном случае указатель на инт).
                 //Pi - это указатель переменная/имя адреса записанного в ячейку

  int** ppi = &pi;
  printf("adres %d of pointer %d, %d\n", ppi, *ppi, **ppi);
  printf("adres of i is %d\n", &i);
//////////////////////////////////////////////////////////////

  char m = 'F';
  char* u = &m; //указатель на чар, положенный в переменную 'u',

  printf("adres of m is &m=>%d and u=>%d\n", u);
//------------------------------------------
  char Flu = 9;
  char* Fff = &Flu;
  printf("\n\npointer to memory cell under the name 'Flu' has itself name 'Fff'\n");
  printf("pointer under the name'Fff' stores in it's memory cell it's content\n");
  printf("it's content is an adres, not int, not float but the adress as a type of data\n");
  printf("it's name is as regular as others but the type of data is an adress\n");
  /*у поинтеров имя такое же, как и у всех остальных. Но при объявлении используется
  соответствующий тип, не int, не float, а int* или float*.
  Операции над этим типом такие=> вывести содержимый адрес, непостредтсвенно
  значение хранящееся в данной ячейке или пройти по адресу, хранящемуся в
  этой ячейке*/
  printf("\n\npointer 'Fff', getting it's content(which is an adress) by writing '&Fff'=>%d\n",&Fff);
  printf("or diving into by direction(adress) it points to and getting what's insde the cell '*Fff'=>%d\n\n\n", *Fff);

  //////--------------------------------------------------------------------------------------

  float nine = 9.99;
  printf("%f\t %p\n", nine, nine); //prints out the adress

  float* pnine = &nine;
  float** ppnine = &pnine;

  printf("adress of pointer pnine is called by dereferencing 'ppnine' => **ppnine %d\n",**ppnine);
  printf("-----------------------------------------------------------------\n");
/////////////////////////////////////////////////////////////////////////////////
  float array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /*chunk of memory brought to you with pointer to initial cell
                                                      as an anchoir*/
  printf("%f\n", *array);
  printf("addressing members of array by raw pointers\n");
  printf("content of array member array[3] by writing *(array+2)=>%f\n", *(array+2) );
  printf("*array gives me initial member, member number 0 =>%f\n", *array);
  printf("there for arrays in c are just raw chunks of virtual memory of const size\n");
  printf("thus array in c is chunk of virtual memory with an adress of zero element\n");
  printf("we can 'walk through memory cells stepping by incrementing pointer'\n");
  printf("for example let's have a float 'ddd':");
  float ddd ;
  scanf("%f", &ddd);
  printf("and a pointer to that cell under name ddd, named itself 'pddd'\n" );
  float* pddd = &ddd;
  printf("the content of the cell under name 'ddd' is %f\n", *pddd);
  printf("the content of the cell to the right of 'ddd' is *(pddd+1), (suposibly integer), %d\n", *(pddd+1));
  printf("or to the left of 'ddd' is *(pddd-1), (suposibly p), %p\n", *(pddd-1));


  return 0;
}
