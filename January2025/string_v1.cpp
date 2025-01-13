/*
 In this file we are still using 4 in stead of (int)sizeof(float)
 to be as simple and explicit as we can
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class string {

    static const int size = 8;
    char* storage = nullptr;
    int index {};
    int last {};
    int totalSize {};
    int usedSpace {};
public:

    string() : usedSpace(index) {
        storage = (char*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    void inflate(int inc = 2) {
        puts("\n");
        printf("entering inflate function\n");
        char* temp = (char*)malloc(index + inc);
        memset(temp, 0, index + inc);
        memcpy(temp, storage, index);
        free(storage);
        storage = temp;
        totalSize = index + inc;
        printf("the total size is now %i\n", totalSize);
        
        printf("exiting inflate float function\n");
        puts("\n");
        
        
    }
    void append(char c) {
        printf("entering append float function\n");
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        if((totalSize - (index)) < 4) inflate(8);
        //pointer arithmentic
        printf("assigning an element into the pointer of index %i\n", index);
        *(storage + index) = f;
        printf("and the contend in the index %i is %f\n", index, *(storage + index));
        printf("the used size is now %i\n", (totalSize - (totalSize - (index + 1))));
        printf("the total size is now %i\n", totalSize);
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        last = index;
        index++;
        
        printf("the index is now %i\n", index);
        printf("the last is now %i\n", last);
        printf("the unused space is %i bytes\n", totalSize - index);
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
        if((totalSize - index) < a_element_size) inflate(a_element_size);
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
        usedSpace += a_element_size;
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
        
    }
    void insert(float ff[], int indx, int a_size) {
        
    }
    float remove(int indx) {
        float f = *(storage + indx);
        *(storage + indx) = 'a';
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
    ~string() {
        free(storage);
    }
};

};

static const int arraySize = 32;

int main(int arc, const char* argv[]) {
    
    puts("\n");
    
    string str1;
    

    str1.append(5.5f);
    str1.append(3.5f);
    str1.append(2.5f);
    str1.append(7.5f);
    str1.append(6.5f);
    str1.append(9.5f);
    str1.print();
    
    printf("adress %p %f\n", str1.storage,  *(str1.storage));
    printf("adress %p %f\n", str1.storage+1,  *(str1.storage+1));
    printf("adress %p %f\n", str1.storage+2,  *(str1.storage+2));
    printf("index is %i\n", str1.getIndex());
    printf("index is %p\n", str1.getStorage());
    puts("\n#########################################################\n");
    
    printf("%zu\n", sizeof(float));
    printf("float %f at index %i\n", str1.getAt(3), 3);
    
    puts("\n#########################################################\n");
    printf("index is %i\n", str1.getIndex());
    str1.remove(3);
    str1.print();
    printf("index is %i\n", str1.getIndex());
    printf("float is %f\n", str1[2]);
    puts("\n#########################################################\n");
    float ff1[] = {1.3, 5.3, 7.4, 4.2, 8.9};
    str1.append(ff1, 5);
    str1.print();
    return 0;
    
}





