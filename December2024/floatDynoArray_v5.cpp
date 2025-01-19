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
    int index {};     //stores location of the next element after existing
    int last {};      //stores the index of the last element
    int totalSize {};


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
        
        printf("exiting inflate float function\n");
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
        last = index;
        index++;
        
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the unused space is %i bytes\n", totalSize - (index * 4));
        printf("and the contend in the index %i is %f\n", index-1, *(storage + (index-1)));
        printf("exiting append float function\n");
        puts("\n");
        
    }
    void append(float ff[], int a_element_size) {
        printf("entering append float array function\n");
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the total size is now %i\n", totalSize);
        if((totalSize - index * 4) < a_element_size) inflate(a_element_size * 4);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        float* ptr = storage + index;
        for(int i=0; i < a_element_size; i++) {
            *ptr = ff[i];
            printf("pointer is %p element is %f\n", ptr, *ptr);
            ptr++;
            last++;
            index++;
        }
        usedSpace += a_element_size * 4;
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the total size is now %i\n", totalSize);
        printf("exiting append float array function\n");
        ptr = nullptr;
        puts("\n");
    }
    int getIndex() const {
        return index;
    }
    float* getStorage() const {
        return storage;
    }
    float getAt(int indx) const {
        
        return *(storage + indx);
    }
    void insert(float f, int indx) {
        printf("entering insert float function\n");
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the total size is now %i\n", totalSize);
        float* ptr = storage + index;
        for(int i=index; i>=indx; i--) {
            *(ptr) = *(ptr--);
        }
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the total size is now %i\n", totalSize);
        printf("exiting insert float function\n");
        ptr = nullptr;
        puts("\n");
    }
    void insert(float ff[], int indx, int a_size) {
        int amountAfter = index - indx;
    }
    float remove(int indx) {
        float f = *(storage + indx);
        *(storage + indx) = 0.0f;
        int amountAfter = index - indx;
        float temp {};
        for(int i=0; i < amountAfter; i++) {
             *(storage + indx + i) = *(storage + indx + i + 1);   //stepping with 4 bytes steps
        }
        last--;
        index--;
        return f;
        
    }
    float remove(int indx1, int indx2) {
        return 0.0f;
    }
    float pop() {
        return 0.0f;
    }
    float& operator[](int indx) {
        return *(storage + indx);
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
    FloatDynoArray() {
        free(storage);
    }
};

};

static const int arraySize = 32;

int main(int arc, const char* argv[]) {
    typedef lint::FloatDynoArray Farray;
    puts("\n");
    
    Farray fa1;
    

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
    printf("index is %i\n", fa1.getIndex());
    printf("index is %p\n", fa1.getStorage());
    puts("\n#########################################################\n");
    
    printf("%zu\n", sizeof(float));
    printf("float %f at index %i\n", fa1.getAt(3), 3);
    
    puts("\n#########################################################\n");
    printf("index is %i\n", fa1.getIndex());
    fa1.remove(3);
    fa1.print();
    printf("index is %i\n", fa1.getIndex());
    printf("float is %f\n", fa1[2]);
    puts("\n#########################################################\n");
    float ff1[] = {1.3, 5.3, 7.4, 4.2, 8.9};
    fa1.append(ff1, 5);
    fa1.print();
    
    puts("\n######################## insert(float f, int indx); ##########################\n");
    
    fa1.insert(6.75, 4);
    fa1.print();
    return 0;
    
}




