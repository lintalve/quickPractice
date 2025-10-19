/*
 So in this file we refresh the view at how user defined objects
 are passed into a function
 */
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <format>
#include <initializer_list>
#include <exception>

#define ALGO 1
static const int size = 9;

namespace lint {

class MyException : public std::exception {
    std::string message {};
public:
    MyException(const std::string& s) : message(s) {
        
    }
    const char* what() {
        return message.c_str();
    }
};

class Vector2 {
public:
    static const int size = 2;
    double vector[2];

    Vector2() { vector[0] = vector[1] = 3.0; }
    Vector2(double x, double y) { vector[0] = x; vector[1] = y; }
    //operator overloading
    Vector2& operator+(const Vector2& rv) {
        std::cout << "left vector + " << std::endl;
        vector[0] += rv.vector[0];
        vector[1] += rv.vector[1];
        return *this;
    }
    Vector2& operator-(const Vector2& rv) {
        vector[0] += -(rv.vector[0]);
        vector[1] += -(rv.vector[1]);
        return *this;
    }
    Vector2& operator*(const int& rvint) {
        vector[0] *= rvint;
        vector[1] *= rvint;
        return *this;
    }
    Vector2& operator*(const float& rvfloat) {
        vector[0] *= rvfloat;
        vector[1] *= rvfloat;
        return *this;
    }
    Vector2& operator*(const double& rvdouble) {
        vector[0] *= rvdouble;
        vector[1] *= rvdouble;
        return *this;
    }
    Vector2& operator*=(const int& rvint) {
        vector[0] *= rvint;
        vector[1] *= rvint;
        return *this;
    }
};



class Vector3{
    static const int size = 3;
    double vector[size] {};
public:
    Vector3() {
        vector[0] = vector[1] = vector[2] = 0.0;
    }
    Vector3(const std::initializer_list<double>& values) {      //const ref to be explisit
        int i{};
        for(auto value : values) {
            if(i<3){
                vector[0] = value;
                i++;
            } else { break; }
        }
    }
    Vector3(float x, float y, float z) {
        std::cout << "initialising vector" << std::endl;
        vector[0] = static_cast<double>(x);
        vector[1] = static_cast<double>(y);
        vector[2] = static_cast<double>(z);
    }
    Vector3(double x, double y, double z) {
        std::cout << "initialising vector from doubles" << std::endl;
        vector[0] = x;
        vector[1] = y;
        vector[2] = z;
    }
    Vector3(const Vector3& v) {
        std::cout << "copying vector " << std::endl;
        vector[0] = v.vector[0];   //it is interresting that you can
        vector[1] = v.vector[1];   //access private variables of other object
        vector[2] = v.vector[2];   //from a member function
    }
    double getX() const { return vector[0]; }
    double getY() const { return vector[1]; }
    double getZ() const { return vector[2]; }
    void setX(double x) { vector[0] =x; }
    void setY(double y) { vector[1] =y; }
    void setZ(double z) { vector[2] =z; }
    //---Operator Overloading---//
    Vector3& operator+(const Vector3& rv) {
        std::cout << "left vector + " << std::endl;
        vector[0] += rv.vector[0];
        vector[1] += rv.vector[1];
        vector[2] += rv.vector[2];
        return *this;
    }
    Vector3& operator-(const Vector3& rv) {
        vector[0] += -(rv.vector[0]);
        vector[1] += -(rv.vector[1]);
        vector[2] += -(rv.vector[2]);
        return *this;
    }
    Vector3& operator*(const int& rvint) {
        vector[0] *= rvint;
        vector[1] *= rvint;
        vector[2] *= rvint;
        return *this;
    }
    Vector3& operator*(const float& rvfloat) {
        vector[0] *= rvfloat;
        vector[1] *= rvfloat;
        vector[2] *= rvfloat;
        return *this;
    }
    Vector3& operator*(const double& rvdouble) {
        vector[0] *= rvdouble;
        vector[1] *= rvdouble;
        vector[2] *= rvdouble;
        return *this;
    }
    Vector3& operator*=(const int& rvint) {
        vector[0] *= rvint;
        vector[1] *= rvint;
        vector[2] *= rvint;
        return *this;
    }
    double operator[](int index) const {
        if(index > 2 || index < 0) throw MyException("index is out of bound");
        return vector[index];
    }
    //needs not to have a return value
    //The temporary Vector2(x, y) is not const, but it can only be accessed in the current expression unless bound to a reference.
    operator lint::Vector2() const {     //needs to be const
        return lint::Vector2();     //needs to return with parenthes (for u-d objects) because the constructor must be called
                                    //to create temporary object, and not be merely a declaration such as Vector2 vec;
    }                               //which is a declaration of the variable vec;
    double magnitude(){
        return sqrt(vector[0]*vector[0] + vector[1]*vector[1] + vector[2]*vector[2]);
    }
    /*
     double magnitude(const Vector3& v){
     return sqrt(v.getX()*v.getX() + v.getY()*v.getY() + v.getZ()*v.getZ(), 2);
     }
     */
    double dot(const Vector3& v){
        return vector[0]*v.getX() + vector[1]*v.getY() + vector[2]*v.getZ();
    }
    Vector3 cross(const Vector3& v){
        return Vector3(vector[1]*v.getZ() - vector[2]*v.getY(),
                       vector[2]*v.getX() - vector[0]*v.getZ(),
                       vector[0]*v.getY() - vector[1]*v.getX());
    }
    
    /*
     bool operator<(const Vector3& v) const {
     return magnitude() < v.magnitude() ? true : false;
     }
     */
    //FRIEND fucking functions!!!! as in Python or in vex len()
    //it's a stand alone fucntion but it has access to the
    //internals of the objects of the certain class!!
    //I'm smart, I'm smart!
    friend double length(const Vector3& v);
    ~Vector3() {
        std::cout << "destructing vector" << std::endl;
    }
};

//------GLOBAL VECTOR FUNCTIONS-------//
double length(const Vector3& v){
    return static_cast<int>(sizeof(v.vector)/sizeof(*v.vector));
}


//-------MATRIX-------//
class Matrix3{
    static const int size = 9;
    double matrix[size];
public:
    Matrix3(){
        for(int i=0; i<size; i++){
            if(i%4){
                matrix[i] = 1.0;
            } else {
                matrix[i] = 0.0;
            }
        }
    }
    ~Matrix3(){
        std::cout << "destructing a matrix" << std::endl;
    }
    Matrix3(float a, float b, float c,
            float d, float e, float f,
            float g, float h, float i) {
        matrix[0] = a; matrix[1] = b; matrix[2] = c;
        matrix[3] = d; matrix[4] = e; matrix[5] = f;
        matrix[6] = g; matrix[7] = h; matrix[8] = i;
    }
    Matrix3(double a, double b, double c,
            double d, double e, double f,
            double g, double h, double i) {
        matrix[0] = a; matrix[1] = b; matrix[2] = c;
        matrix[3] = d; matrix[4] = e; matrix[5] = f;
        matrix[6] = g; matrix[7] = h; matrix[8] = i;
    }
    Matrix3(const Vector3& vec1, const Vector3& vec2, const Vector3& vec3){
        matrix[0] = vec1.getX(); matrix[1] = vec2.getX(); matrix[2] = vec3.getX();
        matrix[3] = vec1.getY(); matrix[4] = vec2.getY(); matrix[5] = vec3.getY();
        matrix[6] = vec1.getZ(); matrix[7] = vec2.getZ(); matrix[8] = vec3.getZ();
        
    }
    Matrix3(float* matrix_array) {
        for(int i=0; i<size; i++) {
            matrix[i] = matrix_array[i];
        }
    }
    Matrix3(double* matrix_array) {
        for(int i=0; i<size; i++) {
            matrix[i] = matrix_array[i];
        }
    }
    //Copy constructor
    Matrix3(const Matrix3& m){
        for(int i=0; i<sizeof(matrix)/sizeof(*matrix); i++) matrix[i] = m.matrix[i];
    }
    Matrix3 rref(){
        std::cout << "perfoming reduced roe echelon form algorithm" << std::endl;
        return Matrix3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    }
    void print(){
        std::string str = std::format("|{0} {1} {2}|\n|{3} {4} {5}|\n|{6} {7} {8}|\n",
                                      matrix[0], matrix[1], matrix[2],
                                      matrix[3], matrix[4], matrix[5],
                                      matrix[6], matrix[7], matrix[8]);
        std::cout << str << std::endl;
    }
    //Since matrix scalar multiplication is not cummutative
    //we implement the following function as a friend function
    //so it can have 2 parameters in the oder from math formula
    friend const Matrix3 operator*(float f, const Matrix3& m);
    friend const Matrix3 operator*(double d, const Matrix3& m);
    friend const Vector3 operator*(const Vector3& v, const Matrix3& m);
    friend const Matrix3 operator*(const Matrix3& lm, const Matrix3& rm);
};

//------GLOBAL VECTOR FUNCTIONS-------//

const Matrix3 operator*(const float f, const Matrix3& m) {
    float local_matrix[size] {};
    for(int i=0; i<sizeof(m.matrix)/sizeof(*m.matrix); i++) {
        local_matrix[i] = m.matrix[i]*f;
    }
    return Matrix3(local_matrix);
}
const Matrix3 operator*(const double d, const Matrix3& m) {
    double local_matrix[size] {};
    for(int i=0; i<sizeof(m.matrix)/sizeof(*m.matrix); i++) {
        local_matrix[i] = m.matrix[i]*d;
    }
    return Matrix3(local_matrix);
}
const Vector3 operator*(const Vector3& v, const Matrix3& m) {
    //Since 3d vector has the same number of rows as the the 3x3 Matrix collumns
    //we can perform following operation
    double x = m.matrix[0]*v.getX() + m.matrix[1]*v.getY() + m.matrix[2]*v.getZ();
    double y = m.matrix[3]*v.getX() + m.matrix[4]*v.getY() + m.matrix[5]*v.getZ();
    double z = m.matrix[6]*v.getX() + m.matrix[7]*v.getY() + m.matrix[8]*v.getZ();
    return Vector3(x, y, z);
}
#if ALGO == 0
const Matrix3 operator*(const Matrix3& lm, const Matrix3& rm) {
    double a = lm.matrix[0]*rm.matrix[0] + lm.matrix[1]*rm.matrix[3] + lm.matrix[2]*rm.matrix[6];
    double b = lm.matrix[0]*rm.matrix[1] + lm.matrix[1]*rm.matrix[4] + lm.matrix[2]*rm.matrix[7];
    double c = lm.matrix[0]*rm.matrix[2] + lm.matrix[1]*rm.matrix[5] + lm.matrix[2]*rm.matrix[8];
    double d = lm.matrix[3]*rm.matrix[0] + lm.matrix[4]*rm.matrix[3] + lm.matrix[5]*rm.matrix[6];
    double e = lm.matrix[3]*rm.matrix[1] + lm.matrix[4]*rm.matrix[4] + lm.matrix[5]*rm.matrix[7];
    double f = lm.matrix[3]*rm.matrix[2] + lm.matrix[4]*rm.matrix[5] + lm.matrix[5]*rm.matrix[8];
    double g = lm.matrix[6]*rm.matrix[0] + lm.matrix[7]*rm.matrix[3] + lm.matrix[8]*rm.matrix[6];
    double h = lm.matrix[6]*rm.matrix[1] + lm.matrix[7]*rm.matrix[4] + lm.matrix[8]*rm.matrix[7];
    double i = lm.matrix[6]*rm.matrix[2] + lm.matrix[7]*rm.matrix[5] + lm.matrix[8]*rm.matrix[8];
    return Matrix3(a, b, c, d, e, f, g, h, i);
}
#elif ALGO == 1

const Matrix3 operator*(const Matrix3& lm, const Matrix3& rm) {
    double matrix[size] = {};
    for(int i=0; i<sizeof(lm.matrix)/sizeof(*lm.matrix); i++){
        for(int j=0; j<sqrt(sizeof(matrix)/sizeof(*matrix)); j++){
            matrix[i] += lm.matrix[i/3*3+j]*rm.matrix[j*3+i%3];
        }
    }
    return Matrix3(matrix);
}
#endif //ALGO

};  //lint namespace
 
//Global functions
//Here we define function to accept by pointer, ref, value
//and return by const or non-const pointer, ref or value


//If the function takes a parameter by non-const reference or pointer,
//you cannot pass a const object, because the function could modify the original object:
lint::Vector3 function1(lint::Vector3 vec1) {    //this parameter behaves like a declaration in terms of accepting const
    return vec1;
}

float func1( float& fl) {  //so passing the argument by reference. Can't pass const. It than loses its constness
    return fl + fl;
}
//When we return to a return variable the following happens -
//the statement after return keyword is an expression or regular variable or object
//and the return type acts as a variable type that is to be binded to that expression, object.
//so the rules of assignment persist
//1) you can assign const to a non const?? //shouldn't loss of const is an error.

const float func2(const float* fl) {  //with this function you accept non-const objects by refs or pointer
    return *fl + 4;             //to accept const pointer is forbiden
    //referencing local temporary object (result of an expresssion)
    //it is undefined behaviour to add 2 pointers
}

//A reference in C++ is essentially an alias for another object,
//meaning that the compiler generates code that uses the memory address of the referenced object.
float func1(const float& fl) {  //what happening is you here make a reference to const.
                                //you bind an object to a const variable, sing - this object is now const
    //float local = fl + fl;    //first see if we are dealing with a reference or a pointer
    //fl+= 3.5;  //ERROR: cannot assign to variable 'fl' with const-qualified type 'const float &'
    return fl;
}

lint::Vector3 func3(const lint::Vector3& vec) {   //so we are declaring (in the argument list we are declaring variables to be binded)
                                    //so we are declaring a const ref (ref to a const object) so later we would bind it at call
                                    //this alias/ref goes into the {} body of the function and via this alias/ref/way of access you can't modify
    return vec;
}

const lint::Vector3& func4(const lint::Vector3& vec) {   //you can return this reference back out from the function anchanged by bynding it outside
    
    return vec;
}

//#######################return values and their types############################
//Next function returns a reference, so the special rules apply:
//apart from the signature/declaration the return type const lint::Vector3& is a const reference (ref to const)
//meaning this is the second part where we decalre the "variable" to accept that, what we are returning
//we can bind the returning variable/object/result_of_an_expression the same way as usuall binding
//and than another binding of this result (effectively the variable fo the return type)
const lint::Vector3& func5(const lint::Vector3& vec) {   //you can return this reference back out from the function anchanged by bynding it outside
//            __________________________________/
//           /
    return vec;
}
lint::Vector3 func6(lint::Vector3& vec) {   //here we breaking the reference by returning from the fanction 'by value', meaning a copy
    return vec;                             //remember if not a reference means copying. So RVO rules apply or mandatory copy elision apply
}                                           //we are not creating a temporary object, we are not creating copy of incoming object,
                                            //we are returning THE reference that came in, but dropping "referenceness" = copying
                                            //but in copying we need to keep constness in binding. binding values ALWAYS comes with copying
                                            //for BOTH builtin types and user-defined types. Binding is copying.

//here is another example
const lint::Vector3& func7() {
    lint::Vector3 vec1{};
    return vec1;
}

void func8(lint::Vector2 v) {
    printf(" qwerl %f\n", v.vector[1]);
}
int main() {
    //using typedef just for the heck of it
    typedef lint::Vector3 Vector3;
    Vector3 vec1 = {1.3, 2.3, 4.2};
    
    const Vector3 vec2 = {3.2, 7.3, 8.5, 1.8, 3.9, 6.4};
    
    const Vector3 vec3 = {1.3, 2.3, 4.2};
    Vector3 vec41 = function1(vec3);  //ERROR: wrong argument, non const variable can't accept const object
    Vector3 vec4 = {1.3, 2.3, 4.2};
    const Vector3 vec5 = function1(vec4);  //can const variable accept non const u-d object?
    const Vector3 vec6 {6.4, 3.6, 7.3};
    Vector3 vec7 = vec6;
    
    float a = 3.0;
    float b = func1(a);
    
    float c = 5.5;
    const float* fptr = &c;    //The key part is that the data being pointed to is treated as const,
                               //meaning you cannot modify it through the pointer. So the way to the content has limitaion.
                               //The actual c remains modifiable directly unless declared as const.
    //*fptr = 5.3;  //ERROR: read-only variable is not assignabl
    
    const float& cr = c;
    //cr += 5.6;
    
    float d = func2(fptr);
    float e = func1(c);
    const Vector3 vec8 = func3(vec4);  //we are passing modifiable object, but reference that accepts it is to const
                                       //so function is designed to only read off the values from the object
                                       //through const functions or read off public member variables
    
    
    
    //return values and their tupes
    puts("#######################return values and their types#########################");
    
    const Vector3& vec10 = func5(vec6);    //so the following error is binding, probably meaning returning binding or outside accepting the value
                                     //And YES, outside binding, you are trying to bind const to not const
                                     //ERROR: binding reference of type 'Vector3' (aka 'lint::Vector3') - accepting type of variable
                                     //to value of type 'const lint::Vector3' - that would be incominng object, declared as a const variable
                                     //drops 'const' qualifier
                                     //func5() should accept a const reference to keep incoming const reference const
                                     //and also return statement/exrpression should keep constness of the reference, since you are
                                     //keeping the reference from parentheses
    
                                     //you can constify a const ref, or just make const ref out of non-const object directly
    //also so
    
    //const Vector3& vec10 = func5(vec6);
    
    //function6 is returning non-const reference for the variable to constify it
    Vector3 vec12;
    Vector3& vecr12 = vec12;
    const Vector3& vec11 = func6(vecr12);    //ERROR: no matching function for call to 'func6'
                                           //That means  we are looking inside the parentheses into arguments and YES:
                                           //argument is a ref! is a const! and accepting parameter is an non-cost
                                           //hense loss of constnes,
                                           //to rectify we pass a non const ref or an obj
                                           //let;s do both
    std::cout << vec3[1] << std::endl;
    
    func8(vec3);
    
    lint::Vector2 vec22;     //no constructor is called?
    lint::Vector2 vec24 {}; //default constructor is called
    lint::Vector2 vec25(2.5, 6.3);
    lint::Vector2 vec23(5.8, 1.9);
    lint::Vector2 vec26 = vec23; //copy constructor is called
    vec25 = vec23; //operator = is called
                   //both lvalues
    lint::Vector2 vec27(5.4, 6.3);
    lint::Vector2 vec28(2.8, 5.3);   //lvalue and rvalue
    lint::Vector2 vec29(7.3, 4.1);   //lvalue and rvalue
    const lint::Vector2& ref = lint::Vector2(1.0, 2.0); // OK   //beaves like const

    
    const lint::Vector2& result = vec23 + vec24 + vec28 + vec26 + vec27 + vec29; //By binding it to ref2, you extend
                                                                         //its lifetime until ref2 goes out of scope.
    //so this result, you can pass it around untill the return statement, end of scope when it would be cleared
    //for perfomace, no need to copy construct like const Vector2 vec 29 = vec23 + ... + vec27
    //for games and stuff;
    //for algorithms that depend on math for openGL, for fluid simulations
    
    //const T&  not modifiable, to pass result around
    const lint::Vector2& ref2 = vec25 + vec24 + vec28 + vec26 + vec27 + vec29;
    
    //RValue reference, modifiable
    //lint::Vector2&& ref3 = vec23 + vec24 + vec28 + vec26 + vec27 + vec29;
    //next line without std::move gave me an error due to subtle compiler issue
    lint::Vector2&& ref3 = std::move(vec23 + vec24 + vec28 + vec26 + vec27 + vec29);
    
    //uniform reference,
    auto&& uniref = vec25 = vec23 + vec24 + vec28 + func6(vec4) + vec27 + vec29 + func6(vec4);
    
    
    //So when passing an expression into a functio, make sure, you're not creating any variables
    //Meaning ref3 was declared/created before it was passed.
    //Because otherwise the line would be:
    //lint::Vector2 v = lint::Vector2&& ref3 = vec23 + vec24 + vec28 + vec26 + vec27 + vec29;
    //which would be nonsensical
    
    func8(ref3 = vec24 + vec28 + vec26 + vec27 + vec29);
    
    //Here we have autotype conversion from vector3 to vector2
    //and an expression with function call
    func8(func6(vec4));
    return 0;
}

