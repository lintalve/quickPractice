#include <iostream>
#include <algorithm>
#include <vector>


static const int mult = 32;

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Lambda function declared and used locally
    //std::for_each(v.begin(), v.end(), [](int n) { std::cout << n * 2 << " "; });
    
    float someFloat =  300.1f;
                    //capturing all by reference
    auto lambda1 = [&](int mlt) { return someFloat*= mlt; };     //don't forget the semicolon
    //lambda1(); //making a call to lambda
    
    std::cout << lambda1(mult) << std::endl;
        //capture by ref  //parameters    //body               //the call
    std::cout << [&someFloat](int mlt) { return someFloat *= mlt;} (mult) << std::endl;
    
    const char* str = "this is a c_string literal";
    //by copy (by value) //params
    std::cout << [&str]() {
        int c {};
        int i {};
        const char* temp = str;
        while((c = *temp) != '\0') {  temp++; i++; }
        return i;
    } () << " is the length of the string" << std::endl;
    
    //lambdas are immutable by default, meaning you can't mutate variables captured by value
    int x {6};
    someFloat = 60.5;
    std::cout << [someFloat, x] () mutable { return someFloat*= static_cast<float>(x);} () << std::endl;

    return 0;
}
