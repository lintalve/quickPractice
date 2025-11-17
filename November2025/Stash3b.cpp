//: C09:Stash4.cpp {O}
#include "Stash4.hpp"
#include <iostream>
#include <cassert>
using namespace std;

const int increment = 100;

int Stash::add(void* element) {

    if(next >= quantity) inflate(increment);   
 
    int startByte = next * size;
    unsigned char* e = (unsigned char*)element;

    for(int i = 0; i < size; i++) *(storage + (startByte + i)) = *(e+i); //copying by byte
    next++;
    return(next - 1);       // Index number
}
void Stash::inflate(int increase) {
    assert(increase >= 0);
    if(increase == 0) return;
    int newQuantity = quantity + increase;
    int newBytes = newQuantity * size;
    int oldBytes = quantity * size;
    unsigned char* b = (unsigned char*)malloc(newBytes);
    for(int i = 0; i < oldBytes; i++) b[i] = storage[i];   // Copy old to new
    free(storage); // Release old storage
    storage = b; // Point to new memory
    quantity = newQuantity; // Adjust the size Adjust the size
} ///