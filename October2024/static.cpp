#include "static.h"
#include <stdio.h>

namespace myFirstNamespace{

///////////////Obj Class Definition//////////////////
const char* Obj::class_name = "Obj";   //this is the c11 rule, this is how you define static const char*
                                         //in the class
Obj::Obj(float x, float y, const char* obj_name) : x(x), y(y){
    printf("Inside constructor of object Obj in myFirstNamespace, initializing an object\n");
    class_name = "Obj";
    name = obj_name;
}
Obj::~Obj(){
    printf("destroing %s of %s class of myFirstNamespace\n", name, class_name);
}
const char* Obj::getClassName(){
    return class_name;
}
const char* Obj::getName(){
    return name;
}


//######################################################//
class Entity{
    int h;
    const char* name;
public:
    Entity(int hh =0) : h(hh) {
        this->name = "Entity";
        printf("object Entity constructor envoked\n");
    }
    ~Entity(){};
};
//Entity::~Entity(){};

Entity ent(4354);  //classes have no memory on linking stage, so no linkage
//static Entity ent(46);

int func2(const int i){  
    //! i++;  //  const, const, const!
    const int d = i;   //is it done while compiling?
    printf("this is the d %d\n", d);
    return d;
}
///////////////////
int incInt(int c){ 
    static const char* func_name = "this is incInt from file static.cpp, from myFirstNamespace";
    printf("%s\n", func_name);
    return c/3;
}

} ////////ends myFirstNamespace

