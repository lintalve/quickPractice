#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 8

typedef struct c_dynoArray {
    float* storage;           //can't initialise variables like in c++
    unsigned int index;       //it wraps around to the maximum value of the type instead.
    size_t space_filled;
    size_t total_space;
} darray;

void da_initialise_default(darray* dptr) {     //do I want to the user to initialise? overload
    dptr->storage = (float*)malloc(SIZE);
    memset(dptr->storage, 0, SIZE);
    dptr->index = 0;
    dptr->space_filled = dptr->index;
    dptr->total_space = SIZE;
}
void da_initialise(darray* dptr, size_t size) {     //do I want to the user to initialise? overload to implement default arg
    dptr->storage = (float*)malloc(size);
    memset(dptr->storage, 0, size);
    dptr->index = 0;
    dptr->space_filled = dptr->index;
    dptr->total_space = size;
}
void da_inflate(darray* dptr, int inc) {
    float* temp = (float*)malloc(dptr->space_filled + inc);
    memset(dptr, 0, dptr->space_filled + inc);
    free(dptr->storage);
    dptr->storage = temp;
}
void da_append(darray* dptr, float f) {      //fewer allocation is better
    if(dptr->total_space - dptr->index <= sizeof(float))  da_inflate(dptr, sizeof(float) * 8);  //In C, arithmetic operators (+ and -) have a
                                                               //higher precedence than relational operators like <= (less than or equal to).
    *(dptr->storage + dptr->index) = f;
    (dptr->index)++;    //float* increments by 4 bytes
    //dptr->space_filled = index * sizeof(float);
    dptr->space_filled += sizeof(float);
}
void da_cleanup(darray* dptr) {
    free(dptr);
}

int main(int argc, const char* argv[]) {
    darray da;
    da_initialise(&da, SIZE);
    da_append(&da, 354.765f);
    da_append(&da, 563.65f);
    da_append(&da, 78.75f);
    printf("float is %f\n", *(da.storage)); //prints   354.339999
    printf("float is %g\n", *(da.storage + 2));
    ывfffff
    return 0;
}
