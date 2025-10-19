#include "static.h"
#include "static_v4.h"
#include <stdio.h>

namespace{                    //testing anonymous namespaces
    int someNewFunc(int i){
        return ++i;
    }
}

//bringing external functions and inbuilt primitives, NO OBJECTS
extern  int anotherConstInt;  // you don't actually need to bring them like this
extern int someInt;
extern const int someExternConstInt;  //yes, need, you must bring it in like that;
extern long someLong;
extern const char* someGlobalString;
//extern Entity ent;   //classes don't have memory as far as linker concerned
////////////////////////FUNCTIONS//////// 
// you must bring functions as well
extern short incFunc(short c=0);  //has defined body else where
extern char incChar(char c);      //it imports it here extern or no
extern int incInt(int c);
extern int func2(const int);  // you must bring external function however...
                              // as a declaration 
extern long longFunc();  //registered, fixed, brought right here, in this file.cpp


int main(void){
//#////////////////////USING EXTERNAL PRIMITIVES//////////////////
    printf("this is anotherConst %d\n", anotherConstInt);
    printf("this is someInt %d\n", someInt);         
    printf("this is someExternConstInt %d\n", someExternConstInt);  //this is how GLOBAL consts
                                                              //work from centralized
                                                              // header  

//#////////////////////USING EXTERNAL FUNCTION//////////////////
    printf("this is anotherConst %d\n", func2(2345));  //
    printf("this is incFunc %d\n", incFunc(287));  //  
    int i =0;
    for(; i<12; i++){
        printf("this is return statement from incFunc %d\n", incFunc());
    }
    printf("this is longFunc %ld\n", longFunc());  //  
    //! using namespace myFirstNamespace;   //you can't use namespace just from neigbouring .cpp
    //using namespace myThirdNamespace;     //if you import a namespace, you add those names
                                            //not replacing current names, hence creating conflicts
                                            
//#//////////////////USING NAMESPACES//////////////////////////////////////////
    printf("this is incInt %d\n", myThirdNamespace::incInt(324));  // 
    //using namespace myThirdNamespace; 
    printf("this is incInt %d\n", myFirstNamespace::incInt(324));  // 
    using myFirstNamespace::incInt;     //using declaration
    printf("this is incInt %d\n", incInt(324));  //  beautiful
    printf("this is someNewFunc %d\n", someNewFunc(452));  //  
    printf("this is some global string %s\n", someGlobalString);  //  
    myFirstNamespace::Obj object1(234.456, 567.23, "object1");  //if your class is declared inside a namespace
                                                    //you MUST use that namespace
    using namespace myThirdNamespace;       //you didn't import myFirstNamespace
                                            //no using myFirstNamespace statement, so compiler 
                                            //only knows Obj class from myThirdNamespace
    Obj object2(263.23f, 575.33f, "object2");
    printf("this is the return value of 'printf' function, %d\n", printf("something\n"));
    printf("this is the value of Obj.x %d\n", static_cast<int>(object2.x)/10);
    object2.x = 234587.35423;
    object2.y = 89023.345;
    printf("this is the value of Obj.y %d\n", static_cast<int>(object2.y)/10%13);
    WithStatic ws = WithStatic();
    ws.printChars();
    
          
    return 0;
}
//using namespace myFunctions;
//using namespace Basic;  
using namespace std;    //declared in every header of stl
                        //but I didn't include any of those
