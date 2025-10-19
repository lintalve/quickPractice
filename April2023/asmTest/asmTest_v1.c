#include <math.h>
#define SOME_SHIT 8

int var0 = 6;

double localVars(int a, int b){
    int val1 = a*a;
    int val2 = b*b;
    double val3 = sqrt(val1 + val2);

    return val3;
}

int main(int args, char* argv[]){
    int x = 3;
    int y = 5;

    double c = localVars(x, y);

    return 0;
}