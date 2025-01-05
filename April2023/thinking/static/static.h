#ifndef STATIC_H
#define STATIC_H
#include <stdio.h>
namespace myFirstNamespace{
//int someInt;
class Obj{
    static const char* class_name;
    const char* name;
    float x;
    float y;
public:
    Obj(float x, float y, const char* name);
    const char* getClassName();
    const char* getName();
    ~Obj();

};
int incInt(int c);


//class Entity{};
}
#endif //ends STATIC_H
