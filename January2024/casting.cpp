#include <stdio.h>

int main(void){
    
    int i = 6;
    int ii = 9;
    float f = 5.64f;
    float ff = 4.1264f;
    double d = 3.38745;
    double dd = 5.345;

    f = i;  //this is promotion to an arguably bigger size type
    printf("this is f now %f \n", f);  // much fucking better, prints 6.000000
    printf("this is f now %.3f \n", f);  // much fucking better, prints 6.000

    d = i;  //IMPLICIT CAST
    printf("this is d now %lf \n", d);
    printf("this is d now %.3lf \n", d);

    ii = ff;   // IMPLICIT CAST
    printf("this is i now %d \n", ii);  // rounds the float
    printf("this is i now %04d \n", ii);  //print 4 digits oeverall and fill it with 0
    
    ii = dd;   // IMPLICIT CAST
    printf("this is i now %d \n", ii);  // rounds the double
    printf("this is i now %04d \n", ii);  //print 4 digits oeverall and fill it with 0

    return 0;
}