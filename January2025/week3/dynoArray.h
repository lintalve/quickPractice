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

void da_initialise_default(darray* dptr);
void da_initialise(darray* dptr, size_t size);
void da_inflate(darray* dptr, int inc);
void da_append(darray* dptr, float f);
void da_cleanup(darray* dptr);


