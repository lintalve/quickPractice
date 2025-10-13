#include "const.h"
#define I 34;

class Entity{
public:
    float x;
    Entity(float x) : x(x) {} 
    ~Entity();
};

Entity getEntity(float x){
    return Entity(234.34f);
}

const Entity getEntity1(float x){
    return Entity(234.34f);
}


const Entity getEntity2(float x){
    const Entity someEntity = Entity(234.34f);
    return someEntity;
}

const int function(int i){return i;}  //const return type is just doesn't do shit for inbuilt types

int func1(const int i){  //const return type is just doesn't do shit for inbuilt types
    //! i++;  //  const, const, const!
    const int d = i;   //is it done while compiling?
    return d;
}

int func2(const int i){  
    //! i++;  //  const, const, const!
    const int d = i;   //is it done while compiling?
    return d;
}


extern int anotherConstInt;
////////////////////////////////////////////////////////////////////////////
int main(){
    //const int u = someConstInt;
    const int i = 34;    //constant, no memory for it
    const int j = i + 3; //const expression, resolved at compile time

    //! i = 43;   // error, can't modify it, it's a const
    const int shit = I + 4;  //similar, compiler resolves it at compile time
    int sh = shit;                         // no memory for it, except when you take its address
    //! int* shit_ptr = &shit;  cannot be done, shit is a const so you need
    // to refer to it as a const like:
    const int* shitPtr = &shit;  // adress of shit is refer to as a pointer to CONST int
    const int* const shitConstPtr = &shit; //const pointer to a const int
    //! const int k;  // all const MUST be initialezed for compiler could resolve it while 
                  // compiling
    const int k = function(i);   //nice!! probbably gets a memory
    //! k++;  //it is a const!!
    int l = func2(k);
    l++;
    int d = func1(k);
    int z = 3;
    const int e = z; // you don't have to make const before run time
                     // you can make them during runtime,like strings
                     // that are immutable, but can be created during run time
    getEntity(32.42f) = Entity(23.23f);  // this is the weirdest part of c++ to me.
    //! getEntity1(32.42f) = Entity(23.23f);  //constant return type of user type
    //! getEntity2(32.42f) = Entity(23.23f);  //constant return type of uset type

    int ccc = anotherConstInt;
    int bbb = someExternConstInt;
    
    return 0;
}