/*
 In this file we implement operator+ to return a temporary object
 so the acociative rule of multiplication wuold work
 and obj1 + obj2 = obj2 + obj1;
 and probably expression obj1 + obj2 = obj2 + obj1 would compile and make sense
 We are passing arrays as pointers, meaning dynamically allocated memory would do
 
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

#define SPACE_USED (index * static_cast<int>(sizeof(T)))

template<typename T>
class darray {
                //this is an implementation, not to make sense to a user
    static const int size = 8;
    T* storage = nullptr;   //increments according to the type
    int index {};     //stores location of the next element after, not current one
    std::size_t totalSize {};
    //this is not very readable, but for a better readability overall down the line
    std::size_t space_used {};  //implementation, initialisation
    void inflate(size_t inc = 8) {
        printf("00 space used is %zu bytes\n", space_used);
        printf("inc %zu elements and %zu bytes\n", inc/sizeof(T),  sizeof(T) * (inc/sizeof(T)));

        T* temp = (T*)malloc(space_used + inc);
        memset(temp, 0, space_used + inc);
        //memcpy(temp, storage, 16);    //doesn't work!! with size_t converted into int!!!
        for(int i=0; i<index; i++)  *(temp + i) = *(storage + i);
        free(storage);
        storage = temp;
        totalSize = space_used + inc;
    }
    //Temporary objects are always const, so make sure you pass in const refs
    darray(T* raw_memory_ptr, int indx, size_t total_size ) :
    index(indx), totalSize(total_size) {   //I'm not sure that I want this constructor to be public
        puts("Constructor for operator+ return const obj");
        storage = (T*)malloc(total_size);
        for(int i=0; i<indx; i++)  *(storage + i) = *(raw_memory_ptr + i);
        space_used = sizeof(T) * index;
        puts("End of Constructor for operator+ return const obj");
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
    darray(darray&& d) noexcept : storage((T*)malloc(d.totalSize)), index(d.index), totalSize(d.totalSize),
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
        if((totalSize - space_used) <= 8) inflate(sizeof(T));
        *(storage + index) = element;
        index++;
        space_used = index * sizeof(T);
    }
    void append(T element_array[], int size_in_elements) {
        printf("element size %i\n", size_in_elements);
        if((totalSize - space_used) < (sizeof(T) * size_in_elements)) inflate(sizeof(T) * size_in_elements);
        //for(int i=0; i<4; i++) {
        //    printf("%g ", *(storage + i));
        //}
        T* ptr = storage + index;
        for(int i=0; i < size_in_elements; i++) {
            *ptr = element_array[i];
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
    const darray operator+(const darray& d) {
        //puts("operator+");
        //printf("the index is now %i\n", index);
        //printf("the total size is now %zu\n", totalSize);
        //inflate(d.length());
        int temp_index = index + d.index;
        T* temp_storage = (T*)malloc(temp_index + 8);
        for(int i=0; i<index; i++) {
            //printf("the storage is now %p\n", storage + (index + i));
            //printf("the one is now %i\n", *(storage + (index + i)));
            //printf("the other is now %i\n", *(d.storage + i));
            *(temp_storage + i) = *(storage + i);
        }
        for(int i=0; i<d.index; i++) {
            //printf("the storage is now %p\n", storage + (index + i));
            //printf("the one is now %i\n", *(storage + (index + i)));
            //printf("the other is now %i\n", *(d.storage + i));
            *(temp_storage + (index + i)) = *(d.storage + i);
        }
        //for(int i=0; i<temp_index; i++) {
        //    printf("%i ", *(temp_storage + i));
        //}
        //puts("\nend of op+ inner test\n");
        //printf("the index is now %i\n", index);
        //printf("the total size is now %zu bytes\n", totalSize);
        return darray<T>(temp_storage, temp_index, totalSize + d.totalSize);    //because I don't have the apropriate constructor
    }
    void print() {
        for(int i=0; i<index; i++) {
            //printf("%i ", *(storage + i));
            std::cout << *(storage + i) << " ";
        }
    puts("\n");
    }
    friend std::ostream& operator<<(std::ostream& os, darray& d) {
        for(int i=0; i<d.index; i++) {
            std::cout << *(d.storage + i) << " ";
        }
        return os << std::endl;;
    }
    ~darray() {
        free(storage);
    }
};

};

int main(int arc, const char* argv[]) {

    /*
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
    //std::cout << fa2 << std::endl;
    */
    puts("\n#########################INTEGER#########################\n");

    lint::darray<int> iar1;
    
    iar1.append(123);
    
    int ii1[] = {156, 456, 234, 879, 245, 675};
    iar1.append(ii1, sizeof(ii1)/sizeof(*ii1));  //here can be, not in the body, where the array deteriorates into a pointer
    iar1.print();
    std::cout << iar1.length() << std::endl;
    
    puts("\n######################### iar3 #########################\n");
    lint::darray<int> iar3 = iar1 + iar1;
    iar3.print();
    std::cout << iar1.length() << std::endl;
    
    puts("\n######################### iar4; #########################\n");
    iar1.print();
    lint::darray<int> iar2;
    int ii2[] = {432, 764, 121, 866, 654, 443};
    iar2.append(ii2, sizeof(ii2)/sizeof(*ii2));
    lint::darray<int> iar4 = iar2 + iar1;
    
    iar4.print();
    std::cout << iar4.length() << std::endl;
    
    lint::darray<int> iar5 = iar1 + iar4;
    iar5.print();
    std::cout << iar5;
    
    puts("\n#########################DOUBLE#########################\n");
    lint::darray<double> dar1;
    
    dar1.append(123.245634);
    dar1.print();
    
    double dd1[] = {156.654, 456.8756, 234.76543, 879.09867, 245.5423, 675.5234, 567.123434};
    dar1.append(dd1, sizeof(dd1)/sizeof(*dd1));  //here can be, not in the body, where the array deteriorates into a pointer
    dar1.print();
    
    lint::darray<double> dar2;
    double dd2[] = {314.654, 2545.8756, 634.76543, 179.09867, 546.5423, 635.5234, 7245.123434};
    dar2.append(dd2, sizeof(dd2)/sizeof(*dd2));
    dar2.print();
    lint::darray<double> dar3 = dar1 + dar2;
    dar3.print();
    double ddd = dar3.at(11);
    std::cout << ddd << std::endl;
    //std::cout << dar1.length() << std::endl;
    //std::cout << dar1.at(4) << " " << dar1[4] << std::endl;
    //puts("\n######################### main methods #########################\n");
    //lint::darray<int> dar2 = dar1;  //Copy constructor
    
    return 0;
    
}





