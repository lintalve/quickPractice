#include <stdio.h>

//no user headers for this one

#define I 34;

int someInt = 2034856;  //you can't separate inbuilt type declaration an dedinition???
int anotherConstInt = 87;    //undefined symbol duting linking!
extern const int someExternConstInt = 32523;  //const must have extern modifier?!
                                              //in order to have an address 
                                              //in order to have linkage?  
long someLong = 29837465;  //quad word primitive    
//and the most importatly we can use strings
static const char* someGlobalString = "this is someString from static_v1.cpp";   
                                      //this is the lowest level implementaion
                                      //of a string, const char*

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
