#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class FloatDynoArray {
    static const int size = 32;
    float* storage = nullptr;
    unsigned int index {};
    unsigned int totalSize;
    int currentSize;
public:
    FloatDynoArray() {
        storage = (float*)malloc(size);
        memset(storage, 0, size);
        currentSize = size;
        totalSize = size;
    }
    void inflate(int inc = 8) {
        printf("entering inflate function\n");
        float* temp = (float*)malloc((index * sizeof(float)) + inc);
        memset(temp, 0, index * sizeof(float) + inc);
        memcpy(temp, storage, index);
        free(storage);
        storage = temp;
        totalSize = index * sizeof(float) + inc;
        printf("the total size is now %i\n", totalSize);
        printf("exiting append float function\n");
        
        
    }
    void append(float f) {
        printf("entering append float function\n");
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        //if((totalSize - index * sizeof(float)) < sizeof(float)) inflate(sizeof(float));
        
        *(storage + index * sizeof(float)) = f;
        printf("and the contend in the index null is %f\n", *(storage + index));
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        
        index++;
        printf("the unused space is %lu bytes\n", (totalSize - index * sizeof(float)));
        printf("exiting append float function\n");
        puts("\n");
        
    }
    void append(float f[], size_t a_size) {
        if(totalSize - index < a_size) inflate(a_size);
        for(int i=0; i < a_size/sizeof(float); i++) {
            *(storage + i) = f[i];
            index++;
        }
        currentSize += a_size;
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
            printf("%f ", *(storage + i*sizeof(float)));
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
    
    fa1.append(4.5f);
    fa1.append(3.5f);
    fa1.append(2.5f);
    fa1.print();
    
    
}
