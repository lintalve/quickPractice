/*
 This implementation of operator+ returns a reference to the current object (*this).
 However, the key issue here is that this behavior is unexpected and unusual
 for an addition operator. Normally, operator+ should create and return a new object
 representing the result of the addition, not modify the left-hand operand.
 
 In this file we still avoiding the the abstractions
 and ownership issues. By ownership I mean
 ownership by the object(object can delete inner parts)
 ownership by client programmer: your library container returns
 its content and transfer ownership(responsability to delete(to aavoid leaks for example))
 to a client code (Code outside your library code)
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
#include <initializer_list>

namespace lint {

template<typename T>
class darray {
                //this is an implementation, not to make sense to a user
    static const int size = 8;
    T* storage = nullptr;   //increments according to the type
    int index {};     //stores location of the next element after, not current one
    int totalSize {};
    //this is not very readable, but for a better readability overall down the line
    int space_used {index * static_cast<int>(sizeof(T))};  //implementation, initialisation
    void inflate(int inc = 8) {
        printf("inc %i elements and %i bytes\n", inc, inc * static_cast<int>(sizeof(T)));
        //for(int i=0; i<4; i++) {
        //    printf("%g ", *(storage + i));
        //}
        //printf("\nkhgfjhtr");
        T* temp = (T*)malloc(space_used + inc);
        memset(temp, 0, space_used + inc);
        //memcpy(temp, storage, 16);    //doesn't work!! with size_t converted into int!!!
        for(int i=0; i<index; i++)  *(temp + i) = *(storage + i);
        
        //for(int i=0; i<4; i++) {
        //    printf("%g ", *(temp + i));
        //}
        free(storage);
        storage = temp;
        totalSize = space_used + inc;
    }
public:
    darray() {
        puts("Default-constructor");
        storage = (T*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    //Copy constructor
    darray(const darray& d) : storage((T*)malloc(d.totalSize)), index(d.index), totalSize(d.totalSize),
                              space_used(d.space_used)  {
        puts("Copy-constructor");
        for(int i=0; i<d.length(); i++) {
            *(storage + i) = *(d.storage + i);
            }
    }
    //Copy operator=
    darray& operator=(const darray& d) {
        puts("Copy operator=");
        storage = d.storage;
        index = d.index;
        totalSize = d.totalSize;
        space_used = d.space_used;
        return *this;
    }
    //Move constructor
    darray(darray& d) noexcept : storage((T*)malloc(d.totalSize)), index(d.index), totalSize(d.totalSize),
                                 space_used(d.space_used) {
        puts("Move-constructor");
        inflate(d.length());
        for(int i=0; i<d.length(); i++) {
            *(storage + (index + i)) = *(d.storage + i);    //in c++ objects of the same type can access privates
        }                                                   //privates and protected of each other
        d.index = {};
        d.totalSize = {};
        d.space_used = d.index * static_cast<int>(sizeof(T));  //implementation, initialisation
        free(d.storage);
        d.storage = nullptr;
    }
    void append(T element) {
        if((totalSize - space_used) < 8) inflate(8);
        *(storage + index) = element;
        index++;
    }
    void append(T element_array[], int a_element_size) {
        printf("element size %i\n", a_element_size);
        if((totalSize - space_used) < (a_element_size * sizeof(T))) inflate(a_element_size * sizeof(T));
        //for(int i=0; i<4; i++) {
        //    printf("%g ", *(storage + i));
        //}
        T* ptr = storage + index;
        for(int i=0; i < a_element_size; i++) {
            *ptr = element_array[i ];
            //printf("pointer is %p element is %f\n", ptr, *ptr);
            ptr++;
            index++;
        }
        ptr = nullptr;
    }
    int length() const {
        return index;
    }

    T* getStorage() const {
        return storage;
    }
    T at(int indx) const {
        
        return *(storage + indx);
    }
    void insert(T f, int indx) {
        printf("entering insert float function\n");
        printf("storage is now %p\n", storage);
        printf("the index is now %i\n", index);
        printf("the total size is now %i\n", totalSize);
        T* ptr = storage + index;
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
        //int amountAfter = index - indx;
    }
    T remove(int indx) {
        T element = *(storage + indx);
        //*(storage + indx) = 0.0f;
        int amountAfter = index - indx;
        for(int i=0; i < amountAfter; i++) {
             *(storage + indx + i) = *(storage + indx + i + 1);   //stepping with 4 bytes steps
        }
        index--;
        return element;
        
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
    darray& operator+(const darray& d) {
        puts("operator+");
        inflate(d.length());
        for(int i=0; i<d.length(); i++) {
            *(storage + (index + i)) = *(d.storage + i);
        }
        return *this;
    }
    void print() {
        for(int i=0; i<index; i++) {
            //printf("%f ", *(storage + i));
            std::cout << *(storage + i) << " ";
        }
    puts("\n");
    }
    ~darray() {
        free(storage);
    }
};

};

int main(int arc, const char* argv[]) {

    
    lint::darray<float> fa1;
    
    
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
    printf("index is %i\n", fa1.length());
    printf("index is %p\n", fa1.getStorage());
    puts("\n######################### getAt(int indx); ################################\n");

    printf("float %f at index %i\n", fa1.at(3), 3);
    
    puts("\n########################### getIndex(); ##############################\n");
    printf("index is %i\n", fa1.length());
    fa1.remove(3);
    fa1.print();
    printf("index is %i\n", fa1.length());
    printf("float is %f\n", fa1[2]);
    fa1.print();
    puts("\n#########################################################\n");
    
    float ff1[] = {1.3f, 5.3f, 7.4f, 4.2f, 8.9f};
    fa1.append(ff1, static_cast<int>(sizeof(ff1)/sizeof(*ff1)));
    fa1.print();
    printf("float %f at index %i\n", fa1.at(3), 3);
    lint::darray<float> fa2 = fa1 + fa1;
    fa2.print();
    /*
    lint::darray<float> fa2 = fa1;
    
    lint::darray<float> fa3 = fa2 + fa1;
    fa2.print();
    fa3.print();
    
    puts("\n######################## insert(float f, int indx); ##########################\n");
    
    fa1.insert(8.34, 4);
    fa1.print();
    puts("\n#########################INTEGER#########################\n");

    lint::darray<int> iar1;
    
    iar1.append(123);
    
    int ii[] = {156, 456, 234, 879, 245, 675};
    iar1.append(ii, sizeof(ii)/sizeof(*ii));  //here can be, not in the body, where the array deteriorates into a pointer
    iar1.print();
    std::cout << iar1.length();
    puts("\n#########################DOUBLE#########################\n");
    lint::darray<double> dar1;
    
    dar1.append(123.245634);
    
    double dd[] = {156.654, 456.8756, 234.76543, 879.09867, 245.5423, 675.5234, 567.123434};
    dar1.append(dd, sizeof(dd)/sizeof(*dd));  //here can be, not in the body, where the array deteriorates into a pointer
    dar1.print();
    std::cout << dar1.length() << std::endl;
    std::cout << dar1.at(4) << " " << dar1[4] << std::endl;
    puts("\n######################### main methods #########################\n");
    lint::darray<int> iar2 = iar1;  //Copy constructor
    lint::darray<int> iar3;
    
    iar3 = iar2 + iar1;
    iar3.print();
     */
    return 0;
    
}

