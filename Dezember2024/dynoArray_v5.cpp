#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace lint {


int siseofCstring(const char* string) {
    int size = 0;
    char c;
    char* temp = (char*)string;
    while((c = *temp) != '\0') {
        temp++;    //remember to increment the pointer
        size++;
    }
    return size;
}

struct CharDynoArray {
    static const int size = 8;
    char* storage = nullptr;
    char* initPtr = nullptr;
    int currentSize {};
    int index {};
public:
    CharDynoArray() {
        storage = (char*)malloc(size);
        initPtr = storage;
        currentSize = size;
    }
    void inflate(int inc = 8) {
        char* temp = (char*)malloc(index + inc);
        memset(temp, 0, currentSize + inc);
        memcpy(temp, storage, currentSize);
        free(storage);
        storage = temp;
        initPtr = storage;
        currentSize += inc;

    }
    void append(char c) {
        
        if("difference, free bytes are > 2")
        storage += index;
        *storage = c;
        printf("the content of storage is %c\n", *storage);
        //index+= sizeof(c);
        index++;
        storage++;
        *storage = '\0';
        storage = initPtr;
        
        printf("index now is %i\n", index);
        
    }
    void append(const char* s) {
        puts("entering append string");
        inflate(siseofCstring(s));
        printf("the storage is now %p\n", storage);
        printf("the storage size is now %i\n", currentSize);
        printf("the index is now %i\n", index);
        
        
        //char* temp = (char*)s;      //temporary string to avoid const
        char c;
        while((c = *(s + index)) != '\0') {
            *(storage + index) = c;       //lvalue expression
            index++;
        }
        printf("the index is now %i\n", index);
        printf("the storage is now %p\n", storage);
        printf("the initPtr is now %p\n", initPtr);
        *(storage + index) = '\0';
        puts("leaving append string");
    }
    void print() {
        const char* s = (const char*)initPtr;
        printf("the content of an array is \"%s\"\n", s);
        /*
        for(int i=0; i<3; i++) {
            printf("%c", *(char*)storage);
            storage++;
            
        }
        */
    }

    ~CharDynoArray() {
        storage = initPtr;
        free(storage);
    }
    
};

};

int main(int argc, const char* argv[]) {
    
    char c1 = 'a';
    char c2 = 'b';
    char c3 = 'c';
    
    const char* str1 = "5678 asldkjfh alsjkdhf ";
    const char* str2 = "falskdh 23412 ghjg ";
    const char* str3 = "41234 asldkjfh dddddd ";
    
    typedef lint::CharDynoArray charray;
    
    charray ch1;
    
    //ch1.append(c1);
    //ch1.append(c2);
    //ch1.append(c3);

    ch1.append(str1);
    ch1.append(str2);
    
    ch1.print();
    
    
    return 0;
}




