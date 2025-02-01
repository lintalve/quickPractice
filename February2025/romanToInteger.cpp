#include <cstdio>
#include <iostream>



int integer(const char* rom, int& length) {
    int integers[] = {1, 5, 10, 50, 100, 500, 1000};
    const char* roman = "IVXLCDM";
    char c;
    int result = 0;
    
    int len = 0;
    const char* temp = rom;
    while((c = *(temp)) != '\0') {
        len++;
        temp++;
    }
    length = --len;
    temp = rom;
    for(int i=length; i>=0; i--) {
        if((c = *(temp + (length - i))) == 'I') {result += integers[0];}
        else if((c = *(temp + (length - i))) == 'V') {result += integers[1];}
        else if((c = *(temp + (length - i))) == 'X') {result += integers[2];}
        else if((c = *(temp + (length - i))) == 'L') {result += integers[3];}
        else if((c = *(temp + (length - i))) == 'C') {result += integers[4];}
        else if((c = *(temp + (length - i))) == 'D') {result += integers[5];}
        else if((c = *(temp + (length - i))) == 'M') {result += integers[6];}
        printf("%zu \n", sizeof(char));
        printf("%p \n", temp + (length - i));
        printf("%c \n", c);
        
    }
    puts("\n");
    return result;
}
int main(int argc, const char* argv[]) {
    int length;
    int result = integer("XXXVII", length);
    printf("length is %i, result is %i\n", length, result);
    return 0;
}
