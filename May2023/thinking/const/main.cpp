#include "Vec.h"
#include "Bounds.h"
#include <stdio.h>
#include <initializer_list>

const float someConstFloat = 13254.2345;   //some quatient that needs to be global
const Bounds boundaries(-122.3242f, -654.234f, -752.234f,
                                122.3242f, 654.234f, 752.234f);

Bounds getBounds(Bounds bs){
    return bs;
}
const Bounds getConstBounds(Bounds bs = Bounds()){
    return bs;
}

const int getConstInt(int i = 123){
    const int n = i;
    return n;
}

int getInt(int i = 13){
    int n = i;
    return n;
}
float& getFloatByRef(float fl = 87.345f){
    float& fr =fl;
    return fr;
}
const float& getConstFloatByRef(float fl = 87.345f){
    const float& fr =fl;
    return fr;
}
//! float& const getConstFloatByRef(float fl = 87.345f){      //'const' qualifier may not be applied to a reference
//!     float& const fr =fl;                         //'const' qualifier may not be applied to a reference
//!     return fr;
//! }
//int getIntArray(){
//    int array[] = {3, 6, 8, 4, 2, 6};
//    return array;
//}
int main(void){

    getBounds(Bounds()) = Bounds(-122.3242f, -654.234f, -752.234f,
                                122.3242f, 654.234f, 752.234f);
    Bounds() = Bounds(-122.3242f, -654.234f, -752.234f,
                                122.3242f, 654.234f, 752.234f);
    Bounds b = Bounds(-122.3242f, -654.234f, -752.234f,
                                122.3242f, 654.234f, 752.234f);
    b = getBounds(Bounds()) = Bounds(-122.3242f, -654.234f, -752.234f,
                                122.3242f, 654.234f, 752.234f);
    printf("Simulation is happening inside afore mentioned boundaries\n");
    printf("This is the minimum (%lf, %lf, %lf)\n", b.getMin().getXd(), 
                                                    b.getMin().getYd(),
                                                    b.getMin().getZd());
    printf("This is the minimum of the temporary object (%lf, %lf, %lf)\n",
                                    getBounds(Bounds()).getMin().getXd(), 
                                    getBounds(Bounds()).getMin().getYd(),
                                    getBounds(Bounds()).getMin().getZd());
    //getConstBounds() = Bounds(-122.3242f, -654.234f, -752.234f,
    //                            122.3242f, 654.234f, 752.234f);
    getBounds(Bounds()).setMin(-234.444f, -88.4234f, -234.654f);
    getBounds(Bounds()).toString();
    getConstInt();  //! = 24;  can't, const return value
    getInt(); // = 56;  also can't, compiler doesn't allow lvalue with 
                   //inbuilt primitive types returned by value
    getFloatByRef() = 24.56f;  //and does allow returned by reference
    //! getFloatByConstRef() = 24.564f;  //but not const inbuilt type
    getConstFloatByRef();
    //! getConstFloatByRef() = 24.56f;  //expression must be a modifiable lvalue
    printf("size of the numeral '234.234' is %zu\n", sizeof(234.234));  //8 bytes
    printf("size of the numeral '234.234f' is %zu\n", sizeof(234.234f)); //4 bytes
    for(int i: {3, 6, 8, 23, 5, 78, 8}) printf("this is i %d\n", i);

    float fl0 = 244.453f;
    float fl1 = 987.234f;
    float& fr = fl0;  
    printf("reference fr %f\n", fr);
    fr = fl1;          // weird, you can't make it const and you can reassign it
    fr++;
    printf("reference fr %f\n", fr);
    return 0;
}