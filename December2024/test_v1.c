#include <stdio.h>


int main() {
    const char* string = "sgasrgertrdgtbhd rsters 345";
    printf("sdgsg %zu",  sizeof(string));
    
    
    int size = 0;
    char c;
    char* temp = (char*)string;
    while((c = *temp) != '\0') {
        temp++;    //remember to increment the pointer
        size++;
    }
    
    printf("the size of the string is %i", size);
}
