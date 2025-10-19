#include "static_v4.h"
#include <stdio.h>

namespace myThirdNamespace{    //congrrats, my first namespace!!
  
///////////Obj definition///////////////////
const char* Obj::class_name = "Obj";

Obj::Obj(double x, double y, const char* obj_name) : x(x), y(y), name(obj_name){   //name from identifier
    printf("condtructing %s of class %s of myThirdNamespace\n", name, class_name);
    //this->obj_name = "someObject";
}

Obj::~Obj(){
    printf("destroying the %s instance of class %s of myThirdNamespace\n",name, class_name);
}
const char* Obj::getName() const {
    return name;
}
const char* Obj::instanceOf(){
    return class_name;
}
double Obj::getX(){ return x;}
double Obj::getY(){ return y;}

void Obj::setX(double x) { this->x = x; }
void Obj::setY(double y) { this->y = y; }
////////////////////


////////////CLASS WithStatic Definition//////////////////////////
//! WithStatic::WithStatic(char id): id(id){ //id is static, must not be static
    //! this->id = id;    //same here, static members can only be initialized in one place
//Initializing members, fields    
int WithStatic::someInt1 = 2341234;
const int WithStatic::someIntArray[] = {234, 35, 7567, 234, 45, 354};
const Obj WithStatic::someObj(24.435f, 68.3242f, "object33");
const char* WithStatic::staticStringLiteral = "initialed in one place static string literal";
//defining methods
WithStatic::WithStatic(){
    printf("WithStatic constructor\n");
}
WithStatic::WithStatic(char id){
    printf("WithStatic constructor\n");
}
WithStatic::~WithStatic(){
    printf("WithStatic destructor\n");
    someObj.~Obj();                      //gets called by the compiler none the less
                                         //last
}
///////////////STATIC METHODS////////////
const char WithStatic::getClassId(){
    return class_id;
}
const Obj WithStatic::getObj(){
    return someObj;
}
double WithStatic::getObj_x(){
    return o.getX();     
          //someObj.x
}

const char* WithStatic::getMemberName() const {
    return o.getName();
}
const char* WithStatic::getClassName() const {
    return "no name for you";
}
const char* WithStatic::getStaticMemberStaticName(){
    return someObj.instanceOf();    //everything is static: member object is static
                                    //member objects class_name is static
                                    // objects method getThatName is static
                                    // outer class method is static
                                    //static method calls static method of 
                                    //static member of user type
}
void WithStatic::printChars(){         
    char ch;
    while((ch = *staticStringLiteral) != '\0'){        //very clever!
        printf("%c ", ch);
        staticStringLiteral++;
    }
    printf("\n");
}


/////////////////////////Functions definitions/////////////
int incInt(int c){ 
    static const char* func_name = "this is incInt from file static_v4.cpp, from namespace myThirdNamecpace";
    printf("%s\n", func_name);
    c++;        //it's in a fucking namespace!!
    ++c;
    c++;
    return c++;

}

} // ends myThirdNamespace

void myThirdNamespace::Obj::outSideFunc(){
    printf("this is outSideFunction defined outside of the namespace using namespace::func notation");
}

