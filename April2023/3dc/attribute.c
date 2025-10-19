#include "attribute.h"
#include <stdio.h>

void initialize(attr* a, char* name){
    a->name = name;
    printf("attribute is initialized");
}

void nullify(attr* a){
    a->intValue =0;
    a->floatValue =0.0f;
    a->boolValue =false;
    printf("attribute is nullyfied");
}