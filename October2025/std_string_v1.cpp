#include <iostream>
#include <string>
#include <cstdio>


int main(int argc, const char* argv[]) {
    std::cout << "##################### -STD=C++11 ######################" << std::endl;
    
    std::cout << "##################### CONSTRUCTING ######################" << std::endl;
    std::string str1;    //creates string with length 0 and no characters
    std::string str2("some wonderful string");   //classic constructor with c string ilteral
    std::string str3 = "another wonderful string";  //copy constructor with c_string linteral
    
    std::string str4 = std::string();   //copy constructor with rvalue, temporary obj. remember to call, its not a declaration
    std::string str5 = str2 + str3;   //copy constructor with rvalue, temporary obj
    std::string str6(str4);   //classic copy constructor
    
    std::string& str7 = str6;  //mutable reference to a string
    const std::string&& str8 = std::string("some string data");  //string const reference to a tenmporary to prolong its life
    auto&& strR = std::string("some other string data");
    std::cout << str8.size() << " " << str8.capacity() << " " << std::endl;
    std::cout << str3.substr(8, 9);  //should produce "wonderful"
    
    std::cout << "##################### CAPACITY ######################" << std::endl;
    //empty
    std::cout << "str2 capacity is " << str2.capacity() << std::endl;
    str2.reserve(512); //set capacity to 512
    std::cout << "str2 capacity after reserve is " << str2.capacity() << std::endl;
    
    std::cout << "##################### SIZING ######################" << std::endl;
    
    str2.size();   //in characters
    str2.length(); //same
    str2.max_size();  //system maximum of chars, a looooot of chars 2^64 chars, 16zeros chars
    str2.reserve();  //reserves memory, manages capacity
    
    std::cout << "str2 size (always in elements(chars)) is " << str2.size() << std::endl;
    str2.append("do I have today");   //appends characters
    std::cout << "str2 size after appending is " << str2.size() << std::endl;
    str2.resize(str2.size() + 7, 'A');  //resizes string, with characters '\0' by default
    std::cout << "str2 size after resizing it with 7 new characters is " << str2.size() << std::endl;
    std::cout << "and the string itself is " << str2 << std::endl;
    str2.resize(str2.size() - 10);  //resizes string
    std::cout << "the size of str2 after shrinking is " << str2.size() << std::endl;
    std::cout << "and the string is now " << str2 << std::endl;
    
    std::cout << "##################### MODIFYING ######################" << std::endl;
    
    std::string str10 = "some text data with sense";
    str10.erase();      //removes characters
    str10.push_back();  //pushes character back
    str10.pop_back();   //removes character from the back
    str10.append();
    
    //operator+=  //modifies *this, than returns it as a reference //appends characters to the end
    str10.replace(); //replaces
    std::cout << "##################### NUMERIC_CONVERSIONS ######################" << std::endl;
    
    std::cout << "##################### ALGORITHMS ######################" << std::endl;
    auto end = str3.end();
    for(auto it = str3.begin(); it != end; it++) {  //loop's initialization statement
        std::cout << *it << " ";   //dereferencing
    }
    puts("\n");    //using only to remember c/c++, includng <cstdio> for one function bloats the code
    
    auto it = str3.begin();    //not redeclaration
    while(it != end) {
        std::cout << *it << " ";   //dereferencing
        it++;
    }
    std::cout << std::endl;
    
    std::cout << "##################### RAW STRINGS ######################" << std::endl;
    const char* raw = R"(This is a raw string \n with "quotes" and backslashes \\)";
    
    std::cout << raw << std::endl;
    
    /*
    std::stoi()
    std::stod()
    std::to_string()
    
    std::string s = std::to_string(42);
    shrink_to_fit()
    
    //STD=C++14: Minor Refinements
    std::string str9 = "some \"data\"";
    std::cout << std::quoted(str9) << std::endl;
    
    //Floating-point precision was improved in std::to_string()
    
    */
    std::cout << "##################### -STD=C++14 ######################" << std::endl;
    //.std::to_string();
    //.std::to_string();
    std::cout << "##################### -STD=C++17 ######################" << std::endl;
    //STD=C++17
    //std::string_view (No Copy, Better Performance)
    //std::string_view allows handling substrings without creating a new string (zero-cost abstraction).
    
    //std::string_view (No Copy, Better Performance)
    //std::string_view allows handling substrings without creating a new string (zero-cost abstraction).
    std::cout << "##################### -STD=C++20 ######################" << std::endl;
#include <format>
    std::string str20;
    /*
     .starts_with();
     .ends_with();
     
    .contains();
     */
    std::cout << "##################### -STD=C++23 ######################" << std::endl;
    //    .append_range();
    //    .replace_with_range();
    return 0;
}
