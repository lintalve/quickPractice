//: C10:Arithmetic.cpp

#include "NamespaceInt.h"

//so you can localise usage of imported names
//you can't get this names outside the function
//local variables are seen only inside the scope
void arithmetic() {
    using namespace Int;
    Integer x;
    x.setSign(positive);
}

int main(){} ///:~
