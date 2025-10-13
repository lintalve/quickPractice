#include <stdio.h>
typedef const char* string;

int string_len(string s){
    int size=0;
    while(*s != '\0'){
        size++;
        s++;
    }
    return size;
}

int main(void){
    string zeroString = "this";
    string someString = "widuhvb this is my custom string";
    string anotherString = "some other string";
    string thirdString = "yet other jucy  string";
    puts(someString);
    putchar('\n');
    //printf("this is the size of %zu\n", sizeof(someString));
    while(*someString != '\0'){
        putchar(*someString);
        someString++;
    }
    putchar('\n');
    putchar('\n');
    //printf("this is the size of the string %d\n", string_len(someString));
    printf("this is the size of the string %d\n", string_len(anotherString));
    printf("this is the size of the string %d\n", string_len(thirdString));
    printf("this is the size of the string %d\n", string_len(zeroString));

    return 0;
}
