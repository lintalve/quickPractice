#include <stdio.h>
#include <stdlib.h>
#include <string>

struct CharDynoArray {
    static const int size = 8;
    const char* Default;
    int currentSize;
    char* dynoArray;
    int index {};
public:
    CharDynoArray() {
        
        dynoArray = (char*)malloc(size);
        Default = dynoArray;
        currentSize = size;
    }
    void inflate(int inc = 8) {
        void* temp = malloc(currentSize + inc);
        memset(temp, 0, currentSize + inc);
        
    }
    void append(char c) {
        *dynoArray = c;
        dynoArray++;
        index++;
    }
    void append(const char* s) {
        //inflate();   //next step
        dynoArray + index;   //pointer arithmetic to keep array index in oder for appen()
        char* temp = (char*)s;      //temporary string to avoid const
        char c;
        while((c = *temp) != '\0') {
            *dynoArray = c;
            printf("%c", c);
            dynoArray++;
            temp++;
            index++;
        }
    }
    void print() {
        const char* s = Default;
        printf("the content of an array is %s\n", s);
    }
    ~CharDynoArray() {
        dynoArray = (char*)Default;
        free(dynoArray);
    }
    
};


int main(int argc, const char* argv[]) {
    
    char c1 = 'a';
    char c2 = 'b';
    char c3 = 'c';
    
    const char* str1 = "falskdh asldkjfh alsjkdhf ";
    const char* str2 = "falskdh 23412 ghjg ";
    const char* str3 = "41234 asldkjfh dddddd ";
    
    typedef CharDynoArray charray;
    
    charray ch1;
    
    ch1.append(c1);
    ch1.append(c2);
    ch1.append(c3);
    
    ch1.append(str1);
    ch1.append(str2);
    ch1.append(str3);
    
    ch1.print();
    
    
    return 0;
}

