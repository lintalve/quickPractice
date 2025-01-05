 #include <stdio.h>
# define N 8
# define ROWS 4
# define ELEMENTS 5


 int main(void) {

    char array[N];  //инкреминация аррея его размер
    char ar[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  //инициализация аррея через количество ячеек
    short int sh_int_array[N];
    int int_array[N];
    printf("%d\n", sizeof(ar));
    printf("%d\n", sizeof(array));
    printf("%d\n", sizeof(int_array));
    printf("%d\n", sizeof(sh_int_array));
    printf("--------------------------------\n");
    //---------------------------------------------
//-----this is bullshit----
    float float_array[N];
    printf("%d\n", sizeof(float_array));
    char k=0;
    for(k; k<N; k++){
        float_array[k] = k+(float)k/10;
        printf("%f\t", float_array[k]);

      }
//-----this is bullshit---- because I NEED TO USE %f!!!
//------MULTIDIMENTIONAL-ARRYS----------
    printf("----------------------------------------------\n\n\n");
    short int TwoDArray[ROWS/*строк*/][ELEMENTS/*элементов в строке*/]= {
      {11, 21, 31, 41, 51}, {61, 71, 81, 91, 101}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}
    };  //rows go first!!
    char i, j;
    //printf("j is %d, i is %d\n", j, i);
    for(i=0; i<ROWS; i++){
        printf("%d %d\t", i, j);
        for(j=0; j<ELEMENTS; j++){
        printf("%d %d %d\t",i,j, TwoDArray[i][j]);
      } printf("\n\n");
    }

   return 0;
 }
