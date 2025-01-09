/*
 In this file we are still using 4 in stead of (int)sizeof(float)
 to be as simple and explicit as we can
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class FloatDynoArray {
public:
    static const int size = 8;
    float* storage = nullptr;
    int index {};
    int totalSize {};
    int usedSpace {};
    

    FloatDynoArray() : usedSpace(index * 4) {
        storage = (float*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    void inflate(int inc = 4) {
        puts("\n");
        printf("entering inflate function\n");
        float* temp = (float*)malloc(index * 4 + inc);
        memset(temp, 0, index * 4 + inc);
        memcpy(temp, storage, index * 4);
        free(storage);
        storage = temp;
        totalSize = index * 4 + inc;
        printf("the total size is now %i\n", totalSize);
        
        printf("exiting append float function\n");
        puts("\n");
        
        
    }
    void append(float f) {
        printf("entering append float function\n");
        
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        if((totalSize - (index * 4)) < 4) inflate(8);
        //pointer arithmentic
        printf("assigning an element into the pointer of index %i\n", index);
        *(storage + index) = f;
        printf("and the contend in the index %i is %f\n", index, *(storage + index));
        printf("the used size is now %i\n", (totalSize - (totalSize - (index + 1) * 4)));
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        
        index++;
        printf("the unused space is %i bytes\n", totalSize - (index * 4));
        printf("exiting append float function\n");
        printf("and the contend in the index %i is %f\n", index-1, *(storage + (index-1)));
        puts("\n");
        
    }
    void append(float f[], size_t a_size) {
        if(totalSize - index < a_size) inflate(a_size);
        for(int i=0; i < a_size/4; i++) {
            *(storage + i) = f[i];
            index++;
        }
        usedSpace += a_size;
    }
    float get(int index) {
        return *storage;
    }
    float& operator[](int index) {
        return *(storage + index);
    }
    FloatDynoArray& operator+(const FloatDynoArray& fda) {
        return *this;
    }
    void print() {
        for(int i=0; i<index; i++) {
            printf("%f ", *(storage + i));
        }
    puts("\n");
    }
};

};


int main(int arc, const char* argv[]) {
    typedef lint::FloatDynoArray Farray;
    puts("\n");
    
    Farray fa1;
    
    float f = 5.2;
    
    float ff1[] = {1.3, 5.5, 7.5, 4.2, 8.9};
    
    fa1.append(5.5f);
    fa1.append(3.5f);
    fa1.append(2.5f);
    fa1.append(7.5f);
    fa1.append(6.5f);
    fa1.append(9.5f);
    fa1.print();
    
    printf("adress %p %f\n", fa1.storage,  *(fa1.storage));
    printf("adress %p %f\n", fa1.storage+1,  *(fa1.storage+1));
    printf("adress %p %f\n", fa1.storage+2,  *(fa1.storage+2));

    
    
    printf("%zu", sizeof(float));
    
    
}


