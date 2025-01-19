#include "stdio.h"
#include "math.h"

double exponent(double num, int exponent) {
    printf("%lf\n", num);
    int i=0;
    double n = num;
    printf("%lf\n", n);
    while(i<exponent-1) {
        puts("===============");
        printf("%lf\n", n);
        n *= num;
        printf("%lf\n", n);
        puts("===============");
        i++;
    }
    return n;
}
double radical(double number, double exponent) {
    return pow(number, 1.0/exponent);
}

int main(int argc, const char* argv[]) {
    
    //double number = 2.0;
    
    double someNumber = exponent(2.0, 3);
    printf("%lf\n", someNumber);
    puts("=============================");
    double realNumber = radical(64.0, 4.0);
    printf("%lf\n", realNumber);
    
    return 0;
}
