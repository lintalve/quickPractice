/*
 This is still line namespace to use everywhere, especially
 on arduino boards, those with AVR8 and ARM cortex cores
 In this file we are still using 4 in stead of (int)sizeof(float)
 We can read v float float float from a .obj file into storage
 to be as simple and explicit as we can
 
 In this file we are getting rid of 2 indexes 'index' and 'last'
 relying on --index, index--, ++index and index++
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace lint {

class FloatDynoArray {
                //this is an implementation, not to make sense to a user
    static const int size = 8;
    float* storage = nullptr;
    int index {};     //stores location of the next element after, not current one
    int totalSize {};
    //this is not very readable, but for a better readability overall down the line
    int space_used {index * static_cast<int>(sizeof(float))};  //implementation
public:
    FloatDynoArray() {
        storage = (float*)malloc(size);
        memset(storage, 0, size);
        totalSize = size;
    }
    void inflate(int inc = 4) {
        float* temp = (float*)malloc(space_used + inc);
        memset(temp, 0, space_used + inc);
        memcpy(temp, storage, space_used);
        free(storage);
        storage = temp;
        totalSize = space_used + inc;
    }
    void append(float f) {
        if((totalSize - space_used) < 4) inflate(8);
        *(storage + index) = f;
        index++;
    }
    void append(float ff[], int a_element_size) {
        if((totalSize - space_used) < a_element_size) inflate(a_element_size * 4);
        float* ptr = storage + index;
        for(int i=0; i < a_element_size; i++) {
            *ptr = ff[i];
            printf("pointer is %p element is %f\n", ptr, *ptr);
            ptr++;
            index++;
        }
        ptr = nullptr;
        puts("\n");
    }
    bool isObj(const char* path) const {   //this pointer is copied inside the function;
        char* localpath = (char*)path;     //if I were to use the parameter??    ???
        int length {};
        while(*localpath != '\0') {
            length++;
            localpath++;    //incrementing the pointer, that means need to reset it afterwards
        }
        printf("length is %i\n", length);
        //reverse the order of incrementation to decrementation
        localpath = (char*)path + --length;
        char ext[4];
        for(int i=3; i>=0; i--) {
            ext[i] = *localpath;
            printf("%c ", *localpath);
            printf("%c ", ext[i]);
            localpath--;
        }
        
        if(ext[0] == '.' && ext[1] == 'o' && ext[2] == 'b' && ext[3] == 'j') {
            return true;
        } else { return false; }
        
    }
    void readObjv(const char* path) {
        if(isObj(path)) {
            FILE* fp = fopen(path, "r");
            puts("shit yeah");
            const char* str;
            char array[128] {};
            while (fgets(array, 126, fp) != NULL) {  //fgets returns char* or NULL if EOF is reached
                if(array[0] == 'v' && array[1] == ' ') {
                    int i=2;
                    int j=0;
                    char arr1[13] {};
                    double d1 {};
                    while(array[i] != ' ') {
                        arr1[j] = array[i];
                        printf("%c", arr1[j]);
                        i++;
                        j++;
                    }
                    
                    //float strtof(const char *nptr, char **endptr);
                    d1 = strtod(arr1, NULL);
                    //code from append float
                    if((totalSize - space_used) < 4) inflate(8);
                    *(storage + index) = static_cast<float>(d1);
                    index++;
                    printf("\ndouble printed as float %f\n", d1);
                    //=======================
                    
                    int k = i+1;
                    int l = 0;
                    char arr2[13] {};
                    double d2 {};
                    while(array[k] != ' ') {
                        arr2[l] = array[k];
                        printf("%c", arr2[l]);
                        k++;
                        l++;
                    }
                    
                    //float strtof(const char *nptr, char **endptr);
                    d2 = strtod(arr2, NULL);
                    //code from append float
                    if((totalSize - space_used) < 4) inflate(8);
                    *(storage + index) = (float)d2;
                    index++;
                    printf("\ndouble printed as float %f\n", d2);
                    //=======================
                    
                    int m = k+1;
                    int n = 0;
                    char arr3[13] {};
                    double d3 {};
                    while(array[m] != '\0') {
                        arr3[n] = array[m];
                        printf("%c", arr3[n]);
                        m++;
                        n++;
                    }
                    
                    //float strtof(const char *nptr, char **endptr);
                    d3 = strtod(arr3, NULL);
                    //code from append float
                    if((totalSize - space_used) < 4) inflate(8);
                    *(storage + index) = (float)d3;
                    index++;
                    printf("\ndouble printed as float %f\n", d3);
                    
                    //=======================
                    
                    puts("\n");
                    str = strdup(array);  //allocates memory for the str, copys old string into the new one
                    printf("%s\n", str);
                }
            }
        } else {
            puts("shit noooo");
        }
    }
    int getIndex() const {
        //return --index;  //can't do, const method, incrementing a member
        return index - 1;
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
    ~FloatDynoArray() {
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
    puts("\n######################## readObj(); ##########################\n");
    fa1.isObj(".obj");
    fa1.readObjv("cube1.obj");
    fa1.print();
    return 0;
    
}









