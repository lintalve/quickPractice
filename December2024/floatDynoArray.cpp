#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class FloatDynoArray {
    static const int size = 8;
    float* storage = nullptr;
    int index;
    int totalSize;
    int currentSize;
public:
    FloatDynoArray() {
        storage = (float)malloc(size);
        memset(storage, 0, size);
        currentSize = size;
    }
    void inflate(int inc = 8) {
        float* temp = malloc(currentSize + inc);
        memset(temp, 0, currentSize + inc);
        memcpy(temp, storage, currentSize);
        free(storage);
        storage = temp;
        totalSize = currentSize + inc;
        
    }
    void append(float f) {
            *storage = f;
            index++;
        }
    void append(float f[]) {
        if((totalSize - currentSize) <= sizeof(f)) inflate(sizeof(f))
        for(int i=0; i < sizeof(f)/sizeof(*f); i++) {
            *storage = f[i];
            index++;
        }
        currentSize += sizeof(f);
    }
    float getat(int index) {
        return *storage;
    }
    
}

};
