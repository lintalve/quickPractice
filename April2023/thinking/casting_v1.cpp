#include <stdio.h>

int main(void){
    
    int i = 6;
    int ii = 9;
    int iii = 0x7fff;  //32767
    float f = 5.64f;
    float ff = 4.1264f;
    float fff = 4.1245664f;
    double d = 63.38745;
    double dd = 75.345;
    double ddd = 15.37562344536086;

    printf("this is d %.3lf\n", d); //just prints first 3 digits of the double value

    //////////////STATIC CAST C++/////////////////////
    f = static_cast<float>(i);  //there you go, more c++ like code
    d = static_cast<float>(i);  //there you go, more c++ like code
    printf("this is f now %.3f\n", f); //fill digits with 0 if nothing is there
    printf("this is d now %.4lf\n", d); //fill digits with 0 if nothing is there
    // next line means I know what I'm doing risking possible loss of data
    i = static_cast<int>(dd);  //possible loss of data due a downgrading
    //to a smaller footprint type
    char c = static_cast<char>(i); //again dowsizing, means I'm risking loss on purpose
    printf("this is i now %d or %04d \n", i, i);  //floors the double
    // you basically just making a cast out in the open 
    // for everybody to acknowledge that you're making a cast
    // in oder to minimize the risk of a mistake
    printf("this is c now %c \n", c); 
    printf("this is c now %d \n", c); 
    dd = static_cast<double>(iii); 
    printf("this is dd now %.3lf\n", dd);  //yes, the same as an implicit
    //upgrading to a bigger footprint type 

    return 0;
}