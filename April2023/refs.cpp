#include <stdio.h>

void incInt(int& a){
    a++;
}
void changeInt(int& b){
    b++;
}
int* givePtr(int* ptr){
    return ptr;
}
int main(void){
    int a = 1123;
    int* pointer_a = &a;
    int& ref = a;  //you don't dereference the variable
    changeInt(a);
    incInt(a);
    int* ptr = givePtr(pointer_a);

    printf("this should be an int %d \n", a);
    incInt(a);
    printf("this should be an int %d \n", a);  
    incInt(a);
    printf("this should be an int %d \n", a);  
    incInt(a);
    printf("this should be value a %d, at adress %p \n", a, ptr);  
    
    return 0;
}