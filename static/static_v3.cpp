#include <stdio.h>
//no user headers for this one


namespace{                 //anonymouss namespace, pins objects to a file scope
int incInt(int c){    
    static const char* func_name = "this is incInt from file static_v3.cpp, from nameless namespace";
    printf("%s\n", func_name);
    return c++;
}
}

int incInt(int c){ 
    static const char* func_name = "this is incInt from file static_v3.cpp, from global space";
    printf("%s\n", func_name);
    return c/2;
}

namespace mySecondNamespace{

int incInt(int c){ 
    static const char* func_name = "this is incInt from file static_v3.cpp, from namespace myFirstNamecpace";
    printf("%s\n", func_name);        //global name, extern or not, has external linkage
    return c++;
}

class Base;  // weird seclaration barely

class Base{
    int i = 3241; 
};
}// ends myFirstNamespace