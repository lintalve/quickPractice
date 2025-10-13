#include <iostream>
#include <string>
#include <format>
#include <print>


int main(int args, const char* argv[]) {
    
    std::cout << "################ SEARCH #################" << std::endl;
    //These functions treat the input string as a set of characters, not a sequence
    std::string str1 = "this is a string containing some data";
    //.find() is the function to find a substring
    std::cout << str1.find("string") << std::endl;    //returns an index, starting with 0
    
    std::cout << str1.find("ng") << std::endl;   //14
    std::cout << str1.rfind("ng") << std::endl;  //25 //works only if multiple occurences

    std::cout << str1.find("string") << std::endl;  //only one occurence of the "string"
    std::cout << str1.rfind("string") << std::endl;  //will give the same position both
    //###########//
    std::cout << "=======================================\n";
    std::string str11 = "new incoming data from the web is mmmmmmmmmmmmmmm";
    std::cout << "the first of m is index " << str11.find_first_of("m") << std::endl;  //find first occurance of characters
    std::cout << "the first of w is index " << str11.find_first_of("w") << std::endl;  //find first occurance of characters
    std::cout << "the first of w is index " << str11.find_first_of('w') << std::endl;  //find first occurance of characters
    std::cout << "the first of ng is index " << str11.find_first_of("ng") << std::endl;  //find first occurance of characters
    std::cout << "the first char not of any of " << str11.find_first_not_of("new incom") << std::endl; //first guess is 9 but 'i' 'n'..
    std::cout << "the last of m is index " << str11.find_last_of("m") << std::endl;
    std::cout << "the last not of m is " << str11.find_last_not_of("m") << std::endl; //find last absense of characters
    std::cout << "the last not of s is " << str11.find_last_not_of("s") << std::endl; //find last absense of characters
    std::cout << "################ FORMAT #################" << std::endl;
    /*
    {:<10} – Left-align in a 10-character field.
    {:>10} – Right-align in a 10-character field.
    {:^10} – Center in a 10-character field.
    {:06} – Pad with zeros (e.g., 000042).
    {:#x} – Hexadecimal with 0x prefix.
    {:.3f} – Fixed-point floating-point with 3 decimal places.
    */
    auto someFloat = 23452.345f;
    auto someDouble = 645.4265467;
    int someInt = 345;
    std::string to_print= std::format("this is some int {1} and some float {0}", someFloat, someInt);
    std::cout << to_print << std::endl;
    
    std::cout << std::format("number is {:<10}\n", 45);    //I thought with 0, but it pads with white spaces ' '
    std::cout << std::format("number is {:>10}\n", 45);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:>10}\n", 45.6353);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:^10}\n", 45.63);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:012}\n", 45);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:012}\n", 45.63);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:#x}\n", 45);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:9f}\n", 45.63);    //10 char field, puts your number to the right
    std::cout << std::format("number is {:9f}\n", someDouble);    //10 char field, puts your number to the right
    
    std::string str2 = std::format("more, than just a float {:.6f} or some int {:#x}", someFloat, someInt);
    //std::print(someInt);
    std::cout << str2 << std::endl;
    
    std::print("some float {}\n", someFloat);
    std::print("some float {:.6}\n", someFloat);
    std::print("the adress of int is {}\n", static_cast<void*>(&someInt));  //adresses don't need {:#x} //have to cast from raw ptr
    
    std::cout << "################ ALGORITHMS #################" << std::endl;
    
    std::string str5 = "very interresting style of formatting and printing";
    
    for(auto it = str5.begin(); it != str5.begin() + str5.find(" style"); it++) {
        std::cout << *it << " ";
    }
    std::print("\n");
    
    std::string::iterator it = str5.begin()++;
    std::size_t i {};
    while(i != str5.find_first_not_of("revysio n")) {
        std::print("{} ", *(it + i));
        i++;
    }                     //it's holding a temp...
    std::print("\n");
    for(auto it = str5.begin(); it != str5.begin() + str5.find_last_of("orfamt"); it++) {
        std::print("{} ", *it);
    }
    std::print("\n");
    for(int j=0; j<str5.size(); j++) {
        std::cout << str5[j] << " ";
    }
    
    std::print("\n");
    
    std::string roman = "XXVII";
    
    int theInt = 745542;
    
    std::print("{}\n", std::to_string(theInt));
    
    [theInt]() mutable { std::print("{}\n", std::to_string(theInt)); } ();
    
    
    return 0;
}
