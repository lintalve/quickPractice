#include <stdio.h>

int* func(int* x){
    (*x)++;     //dereferencing (getting an int), incrementing
    return x;   // safe if you have variable ptr (you do, later in main)
}

int& go(int& x){
    x++;  // the same effect as in func  
    return x;  // safe, x exists outside the function
}

int& shit(){
    int q;
    //! return q;  // Mistake
    static int x;
    return x;  // safe for some reason unnown, 
               //mainly because x exists outside the function
}
int main(){
    int a = 0;
    func(&a);  //appearantly you can call a function without assigning its result
    go(a);
    printf("final value of a is %d \n", a);

    return 0;
}