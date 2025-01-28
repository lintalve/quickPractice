#include <stdio.h>

#define I 33244;


namespace myThirdNamespace{       //you usually declare namespaces in headers
//                             //because they get included into one or many files 
//built in
static int someInt = 5958797;  //if static, then it's local to the file
static int anotherConstInt = 2341;    //undefined symbol duting linking!
static const int someExternConstInt = 98234089;  //const must have extern modifier?!
                                              //in order to have an address 
                                              //in order to have linkage?
//functions
int incInt(int c);
//user classes
class Obj{
    static const char* class_name;    //can't have in-class initializer
    const char* name;        //can't have in-class initializer
public:        
    double x;
    double y;

    Obj(double x, double y, const char* obj_name);
    ~Obj();
    const char* getName() const;
    static const char* instanceOf();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    void outSideFunc();
};

class WithStatic{
    static const int someInt0 = 1243;

    static const char class_id = 'f';
    static const short someShort0 = 29345;
    static const long int someLong = 12437890;
    constexpr static const float fl0 = 299876.29384f;
    constexpr static const double someDouble = 34250798709872345.335089;
    
    static int someInt1;    //static but not const, must be initialized outside
    static const int someIntArray[];  //static const, but an array, can't initialize here
    static const float someFloatArray[];  //another array, can't have in-class initializer
    static const Obj someObj;      //gets destroyed by the compiler the last
                                   //static memory region
                                   //why last??? 
    static const char* staticStringLiteral;
    // static const Obj someObj = Obj(); //user type objects can't have an in-class initializer
    // static int intishe = 24;  //member with in-class initializer must be const
    // static const int* intPtr = &id;   //pointer can't have in-class initializer
    // static float fl1 = 234.6087f;  //member with in-class initializer must be const
    // static const int shit[] = {5, 7, 3, 1, 6, 7, 234};  //a member of type "const int []" cannot have an in-class initializer
    // static const char* someString = "alsdfhaksjdhf";
    // static const char* const someString = "alsdfhaksjdhf";  // can't have in-class initializer
    // static const float flArray[] = {24.5f};   //can't have in-class initializer

//######NON STATIC FIELDS###########////////
    const char* someStringLiteral = "wqerfq";   //not static pointer can have in-class initializer
    int someInt2 = 123;
    const int someInt3 = 5423;
    
public:
    Obj o = Obj(24.435f, 68.3242f, "object44");
    WithStatic();
    WithStatic(char id);
    WithStatic(float fl0, char id = 'd');
    ~WithStatic();

    static const char getClassId();  // static method can't be const method
    static const Obj getObj();  
    static const char* getStaticMemberStaticName();

    const char* getClassName() const;
    const char* getMemberName() const;  //can't be const
    const int getSomeInt(){      //you don't have to separate method declaration
        return someInt1;         //and method definition
    }  

    double getObj_x();
    void printChars();                          //you do it to compile realization and suppply headers
    void callStaticMethod();
};

} // ends myThirdNameSpace
