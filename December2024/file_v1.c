#include <stdio.h>     //io functions including file io
#include <stdlib.h>
#include <string.h>



void fillString(char* sp, FILE* fp) {
    char c;
    while((c = fgetc(fp)) != EOF && c != '\0' && c != '\n') {
        *sp = c;
        printf("%c", c);
        sp++;   //lets see if we can excersise point arithmetic on void*
    }
}


int main(int argc, const char* argv[]) {
    FILE* fp;  //file pointer
    
    fp = fopen("cube.obj", "r");     //c function to open the file in reading mode
    
    
    //get one character from the file
    //char c = fgetc(fp);     //c function to read the character from the file
    
    //while loop to get characters from the file until EOF is reached
    char c;
    while((c = fgetc(fp)) != EOF)  {   //EOF - character like \0 that means End Of File
        printf("%c", c);
    }
    
    
    //fill the string with the string from the file
    
    int i = 0;
    char d;
    char charArray[64];
    
    while((d = fgetc(fp)) != EOF && d != '\0' && d != '\n') {
        charArray[i] = d;
        printf("%c", d);
        i++;
    }
    
    //let's involve malloc(), memset(), free(), realloc()
    
    char* string = (char*)malloc(64);
    memset((void*)string, 0, 64);
    
    fillString( string, fp);
    
    
    const char*  ddd = string;
    printf("%s", ddd);
    
    
    
    fclose(fp);   //closes the file
}
