#include <stdio.h>    
/*
This file is an overview of just basics, types
*/
#define SIZE 12

int size = 32;              
short someShort = 16134;         
long someLong = 57587460;
//integral types arays
int array[SIZE];
short shortArray[SIZE];
//pointers to integral types
char* name1;  //must have out of class initialisation
char* name2;  //must have out of class initialisation
//floating point types
//static const double someDouble = 245.970897;   //error: in-class initializer for static data member of type 'const double' requires 'constexpr' specifier
float someFloat = 34.5234f; //a member with an in-class initializer must be const
const double someDouble = 245.970897; 
    
//CONSTEXPRession
const int size = 32;                //read only variable
short someShort = 16134;           //read only variable
long someLong = 57587460;
//non-const 
// static int someInt = 4345; //a member with an in-class initializer must be const
int anInt; //must be initialised outside the class, variable
int array[SIZE];
float fl;


//#############################################################################//
//#############################################################################//
//#############################################################################//
//#############################################################################//


//integral types
const int size = 32;                //read only variable
const short someShort = 16134;           //read only variable
const long someLong = 57587460;
//integral types arays
const int array[SIZE];
//pointers to integral types
const char* name1;  //must have out of class initialisation
const char* name2;  //must have out of class initialisation
//floating point types
//static const double someDouble = 245.970897;   //error: in-class initializer for static data member of type 'const double' requires 'constexpr' specifier

//non-const 
// static int someInt = 4345; //a member with an in-class initializer must be const
int anInt; //must be initialised outside the class, variable
int array[SIZE];
float fl;


//integral types
static const int size = 32;                //read only variable
static const short someShort = 16134;           //read only variable
static const long someLong = 57587460;
//integral types arays
static const int array[SIZE];
//pointers to integral types
static const char* name1;  //must have out of class initialisation
static const char* name2;  //must have out of class initialisation
//floating point types
//static const double someDouble = 245.970897;   //error: in-class initializer for static data member of type 'const double' requires 'constexpr' specifier

//non-const 
// static int someInt = 4345; //a member with an in-class initializer must be const
static int anInt; //must be initialised outside the class, variable
static int array[SIZE];
static float fl;

int main(int argc, const char* argv[]) {
    return 0;
}