#include <math.h>
#define SOME_SHIT 8

int var0 = 6;

const int var4 = 7;
const int var5 = 9;

double localVars(int a, int b){
    int val1 = a*a;
    int val2 = b*b;
    double val3 = sqrt(val1 + val2);

    return val3;
}

int main(int args, char* argv[]){

    int arr[SOME_SHIT];
    int array[var4];
    int array1[] = {};
    int array2[] = {5, 5, 2, 7, 8, 9, 6, 4, 2, 0};

    int x = 3;
    int y = 5;

    double c = localVars(x, y);

    return 0;
}