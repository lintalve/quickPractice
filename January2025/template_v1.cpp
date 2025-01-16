/*
 This is still line namespace to use everywhere, especially
 on arduino boards, those with AVR8 and ARM cortex cores
 In this file we are still using 4 in stead of (int)sizeof(float)
 We can read v float float float from a .obj file into storage
 to be as simple and explicit as we can
 
 let's make it template, shall we?
 this template is meant for inbuilt types, no more than 8 bytes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

namespace lint {

template<class T>
class DynoArray {
                //this is an implementation, not to make sense to a user
    static const int size = 8;
    T* storage = nullptr;   //increments according to the type
    int index {};     //stores location of the next element after, not current one
    int totalSize {};
    //this is not very readable, but for a better readability overall down the line
    int space_used {index * static_cast<int>(sizeof(T))};  //implementation
public:
    DynoArray() {
        storage = (T*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    void inflate(int inc = 8) {
        T* temp = (T*)malloc(space_used + inc);
        memset(temp, 0, space_used + inc);
        memcpy(temp, storage, space_used);
        free(storage);
        storage = temp;
        totalSize = space_used + inc;
    }
    void append(T element) {
        if((totalSize - space_used) < 8) inflate(8);
        *(storage + index) = element;
        index++;
    }
    void append(T element_array[], int a_element_size) {
        if((totalSize - space_used) < a_element_size) inflate(a_element_size * sizeof(T));
        T* ptr = storage + index;
        for(int i=0; i < a_element_size; i++) {
            *ptr = element_array[i];
            //printf("pointer is %p element is %f\n", ptr, *ptr);
            ptr++;
            index++;
        }
        ptr = nullptr;
        puts("\n");
    }
    int getIndex() const {
        //return --index;  //can't do, const method, incrementing a member
        return index - 1;
    }

    T* getStorage() const {
        return storage;
    }
    T getAt(int indx) const {
        
        return *(storage + indx);
    }
    void insert(T f, int indx) {
        printf("entering insert float function\n");
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the total size is now %i\n", totalSize);
        float* ptr = storage + index;
        for(int i=index; i>=indx; i--) {
            printf("the i is %i\n", i);
            printf("ptr is  %p\n", ptr);
            *(ptr) = *(ptr - 1);
            ptr--;
        }
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the total size is now %i\n", totalSize);
        printf("exiting insert float function\n");
        *(storage + indx) = f;
        ptr = nullptr;
        index++;
        puts("\n");
    }
    void insert(T ff[], int indx, int a_size) {
        int amountAfter = index - indx;
    }
    T remove(int indx) {
        float f = *(storage + indx);
        *(storage + indx) = 0.0f;
        int amountAfter = index - indx;
        float temp {};
        for(int i=0; i < amountAfter; i++) {
             *(storage + indx + i) = *(storage + indx + i + 1);   //stepping with 4 bytes steps
        }
        index--;
        return f;
        
    }
    T remove(int indx1, int indx2) {
        return 0.0f;
    }
    T pop() {
        return 0.0f;
    }
    T& operator[](int indx) {
        return *(storage + indx);
    }
    DynoArray& operator+(const DynoArray& fda) {
        return *this;
    }
    void print() {
        for(int i=0; i<index; i++) {
            //printf("%f ", *(storage + i));
            std::cout << *(storage + i) << " ";
        }
    puts("\n");
    }
    ~DynoArray() {
        free(storage);
    }
};

};

int main(int arc, const char* argv[]) {
    typedef lint::DynoArray<float> farray;
    typedef lint::DynoArray<int> iarray;
    puts("\n");
    
    farray fa1;
    

    fa1.append(5.5f);
    fa1.append(3.5f);
    fa1.append(2.5f);
    fa1.append(7.5f);
    fa1.append(6.5f);
    fa1.append(9.5f);
    fa1.print();
    
    printf("adress %p %f\n", fa1.getStorage(),  *(fa1.getStorage()));
    printf("adress %p %f\n", fa1.getStorage()+1,  *(fa1.getStorage()+1));
    printf("adress %p %f\n", fa1.getStorage()+2,  *(fa1.getStorage()+2));
    printf("index is %i\n", fa1.getIndex());
    printf("index is %p\n", fa1.getStorage());
    puts("\n######################### getAt(int indx); ################################\n");

    printf("float %f at index %i\n", fa1.getAt(3), 3);
    
    puts("\n########################### getIndex(); ##############################\n");
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
    
    fa1.insert(8.34, 4);
    fa1.print();
    puts("\n##################################################\n");

    iarray iar1;
    
    iar1.append(123);
    
    int ii[] = {156, 456, 234, 879, 245, 675};
    iar1.append(ii, 6);  //here can be, not in the body, where the array deteriorates into a pointer
    iar1.print();
    return 0;
    
}









