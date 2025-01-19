//for some reason can't fail memory allocation

#include <iostream>
#include <cstdio>
#include <new>

static const long int size = 999999999999;

void no_memory() {
    puts("couldn't allocate your memory\n");
}

void* operator new(size_t sz) {
    void* m = malloc(sz);
    if(m) {
        printf("allocating %zu bytes\n", sz);
        return m;
    }
    exit(1);
}


int main(int argc, const char* argv[]) {
    
    std::set_new_handler(no_memory);
    while(1) {
        int* intArray = new int[size];
    }
    
    //printf("the pointer is %p\n", intArray);
    //malloc(size);
    return 0;
}
