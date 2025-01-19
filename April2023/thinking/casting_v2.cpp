#include <stdio.h>

void func(int){};   //my first nameless argument

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
    bool shit = true;  //native support, nice

    printf("this is d %.3lf\n", d); //just prints first 3 digits of the double value

    //////////////STATIC CAST C++/////////////////////
    void* vp = &iii; //void pointer taking ANY address, directly
                     //means you can always convert to void*
    void* void_p = &fff; //void pointer taking ANY address directly
    void* void_ptr = static_cast<void*>(&ddd);  //much better
    printf("this is the address of iii %p\n", &iii);
    printf("this is the address of iii, assigned to a void pointer vp %p\n", vp);
    //! float* fp = vp;  // casting void* to float* in old c-style casting RISKY
    float* fp = (float*)vp;  // casting void* to float* in old c-style casting RISKY
                             //but not like in c, in c you can ommit (float*) casting
                             //float pointer take ONLY float pointer, not like in c
    
    printf("this is the address of iii, casted to a float* and\
 assigned to a float pointer fp %p\n", fp);
    fp = static_cast<float*>(void_p);  // new but still RISKY using static_cast OPERATOR
    printf("this is the address of fff %p\n", &fff);
    printf("this is the address of fff, c++ OPERATOR static_cast'ed to a float* and\
 assigned to a float pointer fp %p\n", fp);
    func(ff);    // implicit casting, hard to find such a mistake
    func(static_cast<int>(ff));    // explicit cast, do yourself a favour
                                   // supresses warning, when you do it explicit
    return 0;
}