//in this file we explore deleting some void and built in types
//and also look and initializer_list constructor
#include <cstdio>
#include <iostream>
#include <initializer_list>

static const int size = 24;

struct Vector3 {
    static const int size {3};
    double data[size];
    
    Vector3() {
        std::cout << "constructing a Vector3" << std::endl;
        data[0] = data[1] = data[2] = 0.0;
    } //is here for the array
    Vector3(double a, double b, double c) {
        data[0] = a;
        data[1] = b;
        data[2] = c;
    }
    Vector3(float a, float b, float c) {
        std::cout << "constructing a Vector3" << std::endl;
        data[0] = static_cast<double>(a);
        data[1] = static_cast<double>(b);
        data[2] = static_cast<double>(c);
    }
    Vector3(std::initializer_list<double> ir) {
        int count {};
        for (auto value : ir) {
            if(count >= 3) break;
            data[count] = value;
            count++;
        }
    }
    //copy consntructor needed with pointers, otherwise generated
    Vector3(const Vector3& v) {
        std::cout << "copy constructing" << std::endl;
        data[0] = v.data[0];
        data[1] = v.data[1];
        data[2] = v.data[2];
    }
    //Copy assignment operator
    Vector3& operator=(const Vector3& v) {
        std::cout << "copy assigning a Vector3" << std::endl;
        data[0] = v.data[0];
        data[1] = v.data[1];
        data[2] = v.data[2];
        return *this;
    }
    Vector3(Vector3&& v) noexcept {
        data[0] = v.data[0];
        data[1] = v.data[1];
        data[2] = v.data[2];
        //no leave the move from object in empty valid state
        v.data[0] = v.data[1] = v.data[2] = 0.0;
    }
    Vector3& operator=(Vector3&& v) noexcept {
        data[0] = v.data[0];
        data[1] = v.data[1];
        data[2] = v.data[2];
        //no leave the move from object in empty valid state
        v.data[0] = v.data[1] = v.data[2] = 0.0;  //chain assignment, also possible with u-d objects
        return *this;
    }
    
    ~Vector3() {
        std::cout << "destructing a Vector3" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, Vector3& v) {
        return os << "(" << v.data[0] << ", " << v.data[1] << ", " << v.data[2] << ")";
    }
};

int main(int argc, const char* argv[]) {
    
    int* int1 = new int(345); //pseudo constructor form
    printf("int 1 adress: %p\n", int1);
    float* float1  = new float(24.234f);
    printf("float1 adress: %p\n", float1);
    Vector3* v1 = new Vector3;
    printf("v1 adress: %p\n", v1);
    
    void* voPtr = int1;
    printf("voPtr adress: %p\n", voPtr);
    voPtr = float1;
    printf("voPtr adress: %p\n", voPtr);
    voPtr = v1;
    printf("voPtr adress: %p\n", voPtr);
    
    void* ptr = new Vector3;        //you can temporariry to store it in a container
    void* ptrArr = new Vector3[size];
    
    //delete ptr;  //WARNING: delete on void* Is Not Allowed, cast back!!
    //You MUST cast it back before delete to call destructor!!
    delete (Vector3*)ptr;  //WARNING: delete on void* Is Not Allowed,
    
    //delete [size]ptrArr;   ERROR: //old notation
    //You MUST cast it back before delete to call the destructor!!
    delete [](Vector3*)ptrArr;   //CAST BACK!!
    
#define FREE 1
#if FREE == 1
    //delete voPtr; ERROR: delete void is not allowed, cast back
    free(int1);
    free(float1);
    free(voPtr);  //It is your responsibility to track info behind void*
#elif FREE == 0
    delete int1;
    delete float1;
    //ERROR: delete voPtr;
#endif
    
    //This all means that in c and c++ you CAN and
    //should assign any pointer to a void*
    
    //You can't delete void*, which is safer meaning
    //you must cast your objects back before delete it
    //meaning you can delete only what you new allocate
    
    
    Vector3 v3 {5.3, 7.2, 12.6, 8.2, 9.54};
    std::cout << v3 << std::endl;
    
    return 0;
}

