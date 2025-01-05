#include <stdio.h>

# define N 16

int main(void) {
    typedef  short int sh_int;
    sh_int a = 4465;
    int b;
    printf("%d\n", a);
    printf("%lu\n", sizeof(a));
    printf("size of b = %lu\n", sizeof(b));
///////////////////////
    sh_int array[N];///
///////////////////////
    sh_int i = 0;
    printf("printing declared array with raw RAM\n");    // объявил итератор и определил его равным 0;
    for (int i =0; i<N; i++)  // не нужно explisit объявлять типа int i = 0;
        printf("%d\n", array[i]);
//-------------------------------------
//printf("-----------------------" );
    printf("increminator has changed to %d\n", i);  //таки изменил итератор i инкреминацией выше
    i=0;
    for(; i<N; i++){
        array[i] = i;
        printf("%d\n", array[i]);
    }

    printf("array has changed by the loop-------------------\n" );//-------------------------------------
    printf("printing changed array again----------\n" );//-------------------------------------
    i=0;
    for (; i<N; i++)
        printf("%d\n", array[i]);
    printf("now let's print direct forward count with backward cell filling\n");
    i=0;
    for(; i<N; i++){
       array[N-i-1]=i;    //в квадратных скобках, в доступе к ячейке можно писать вычислимое выражение, expression
       printf("step:%d\t printing cell index:%d\t value of it:\t %d, changing cell of index: %d, to a value:%d \n", i+1, i, array[i], (N-i-1), array[N-i-1]);
    }
//-----------------------------------------------------------------------------------------------------------
    printf("----------------------------------------\n" );
    i=0;
    for(; i<N; i++){
        array[i] = i%2;
        printf("cell of index%d, ontains:%d\n", i, array[i]);
    }
    printf("----------------------------------------\n" );
    //--------------------------------------------------------------


    i=0;
    for(; i<N/2; i++){  //run iterator half the length times
        array[2*i] = i;
    }
    for(; i<N/2; i++){
        array[2*i+1] = N/2+i;
    }
    for(; i<N; i++){
        printf("%d", array[i]);
    }



  return 0;
}
