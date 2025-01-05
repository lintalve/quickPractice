//присваивание функции в переменную

#include <iostream>


void HelloWorld(int a){
    std::cout <<"Hello World value:" <<a<<std::endl;
}

//-------------------------------------------------
int main() {

    //auto function = HelloWorld;
    void(*function)() = HelloWorld;
    typedef void(*HWfunction)(int a);
    HWfunction function = HelloWorld;
    function(8);
    //std::cin.get();
    return 0;
}
