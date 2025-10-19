//with this file we learn how to
//set our own new_handle(); for handling out_of_memory situations

#include <cstdio>
#include <iostream>


static const long int size = 999999999999;

void* operator new(size_t sz) noexcept(false) {
    printf("allocating %zu bytes", sz);
    void* m = malloc(sz);
    if(!m) {
        puts("failure");
    }
    return m;
}

void out_of_memory() {
    puts("couldn't allocate the requestet chunk of memory");
    exit(1);
}

int main(int argc, const char* argv[]) {
    //the following function you call inside main
    //and pass the name of your custom function to deal
    //with memory allocatio faluire
    std::cout << "setting the new_handler" << std::endl;
    std::set_new_handler(out_of_memory);
    
    int* intArray = new int[size];
    delete []intArray;  //correct syntax, without [size]
    return 0;
}
