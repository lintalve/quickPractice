//: C10:OverridingAmbiguity.cpp
#include "NamespaceMath.hpp"
#include "NamespaceOverriding2.hpp"
void s() {
    using namespace Math;
    using namespace Calculation;
    
    // Everything's ok until:
    // divide(1, 2);
    // Ambiguity
}

int main() {} ///:~
