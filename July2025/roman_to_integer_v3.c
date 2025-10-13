#include <stdio.h>

int roman_to_integer(char* array) {
    int integer = 0;
    while(*array != '\0') {
        switch(*array) {
            case 'I' :
                integer +=1;
                break;
            case 'V' :
                integer +=5;
                break;
            case 'X' :
                integer +=10;
                break;
            case 'L' :
                integer +=50;
                break;
            case 'C' :
                integer +=100;
                break;
            case 'D' :
                integer +=500;
                break;
            case 'M' :
                integer +=1000;
                break;
        }
        //printf("int is %c \n", *array);
        array++;
    }
    return integer;
}

int main(int argc, const char* argv[]) {
    char array[24];
    char* roman;     //putting scanf here may cause issuues
    puts("enter a roman literal");
    scanf("%s", array);
    int integer = roman_to_integer(array);
    printf("%i", integer);

    return 0;
}
