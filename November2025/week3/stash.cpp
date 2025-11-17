#include <iostream>


/*
so we are adding elements via their addresses?..
why not overload constructors?
*/

class Stash {
    static const int increment = 16;
    
    int size;
    int next; //in ints
    int capacity; //in bytes
    unsigned char* storage = nullptr;
    void inflate(int increase);
    Stash() : size(0), next(0), capacity(0) {}
    Stash(int sz, int amount) : size(sz), next(0), capacity(0) {
        inflate(amount);
    }
public:
    
    Stash(int sz) : size(sz), next(0), capacity(0) {
        inflate(increment);
    }
    Stash& add(void* element);
    int getCapacity() const { return capacity; }
    int getIndex() const { return next; }
    void* fetch(int index) const {
        if(index < 0 || index >= next) return 0;
        return (storage + (index * size)); 
    }
    ~Stash() {free(storage); }

    

};
Stash& Stash::add(void* element) { //void* can accept all other pointers
    if((next*size) >= capacity)inflate(increment);
    unsigned char* e = (unsigned char*)element;
    int startByte = next*size;
    for(int i=0; i<size; i++) *(storage + (startByte + i)) = *(e+i);
    next++;
    return *this;
}
void Stash::inflate(int increase) {
    int new_capacity = capacity + increase;
    unsigned char* temp = (unsigned char*)malloc(new_capacity);
    for(int i=0; i < next*size; i++)
        *(temp + i) = *(storage + i);
    free(storage);
    storage = temp;
    free(temp);
    temp = nullptr;
    capacity = new_capacity;
}



int main(int argc, const char* argv[]) {
    
    Stash intStash(sizeof(int*));

    int someInt = 234;    

    for(int i=0; i<64; i++) {
        int ii = i*2;
        intStash.add(&ii);
    }

    //intStash.add(&someInt);

    //printf("%i\n", *((int*)intStash.fetch()));
    printf("%i\n", intStash.getCapacity());

    int anInt = *(int*)(intStash.fetch(32)); //void pointers cannot be dereferenced

    printf("the number is %i\n", anInt);
    
    return 0;
}