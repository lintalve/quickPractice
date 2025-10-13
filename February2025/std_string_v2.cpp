//Here we are using pure c++
#include <iostream>
#include <string>


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
    sttr2.empty()  //bool, empty or not
    
    std::cout << "str2 capacity is " << str2.capacity() << std::endl;
    str2.reserve(512);
    std::cout << "str2 capacity after reserve is " << str2.capacity() << std::endl;
    str2.max_size();  //system maximum of chars, a looooot of chars 2^64 chars, 16zeros chars
    std::cout << "##################### SIZING ######################" << std::endl;
    
    str2.size();   //in characters
    str2.length(); //same
    
    
    
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
    str10 += str9;
    str10 += "addition";
    str10 += str8 + str7 + "words";
    str10.replace(); //replaces
    str10.copy();
    str10.swap();
    std::cout << "##################### SEARCH ######################" << std::endl;
    std::string str11 = "new incoming data from the web";
    str11.find("a");   //char or a string??
    str11.rfind("a");
    str11.find_first_of("data");  //find first occurance of characters
    str11.find_first_not_of("m"); //find first absence of characters
    str11.find_last_of("from");
    str11.find_last_not_of("data"); //find last absense of characters
    
    std::cout << "##################### OPERATIONS ######################" << std::endl;
    
    std::string str12 = "this program runs correctly";
    str12.compare("this program runs correctly");    //compares two strings
    str12.substr(5, 7); //should return "program"
    
    std::cout << "##################### NON_MEMBER_FUNCTIONS ######################" << std::endl;
    
    //global operator+
    std::string str13 = "this program";
    std::string str14 = "that I wrote";
    std::string str15 = str13 + str14;
    std::string str16 = "hello" + "world";  // should call two constructors and resulting temps are arguments for the "+"
    
    //global operator==
    std::string str17("this program");
    std::cout << str13 == "this program" << std::endl;
    std::cout << "##################### NUMERIC_CONVERSIONS ######################" << std::endl;
    
    std::string str18 = "-12650";
    std::string str19 = "-24692837459";
    std::string str20 = "-20348765998767987";
    
    std::string str21 = "12650";
    std::string str22 = "24692837459";
    std::string str23 = "20348765998767987";
    
    std::cout << std::stoi(str18); << std::endl;   //string to integer
    
    std::cout << std::stol(str19); << std::endl;
    
    std::cout << std::stoll(str20); << std::endl;
    
    
    std::cout << std::stoul(str22); << std::endl;
    
    std::cout << std::stoull(str23); << std::endl;
    
    std::string str24 = "234.534";
    std::string str25 = "35234.75644";
    std::string str26 = "20348765998.767987";
    
    std::cout << std::stof(str24); << std::endl;
    
    std::cout << std::stod(str25); << std::endl;
    
    std::cout << std::stold(str26); << std::endl;
    
    int someInt = 2452;
    float someFloat  = 765.754f;
    double someDouble = 5745756.2342;
    
    std::cout << std::to_string(someInt); << std::endl;
    
    std::cout << std::to_string(someFloat); << std::endl;
    
    std::cout << std::to_string(someDouble); << std::endl;
    
    std::cout << "##################### ALGORITHMS ######################" << std::endl;
    
    
    auto end = str3.end();
    for(auto it = str3.begin(); it != end; it++) {  //loop's initialization statement
        std::cout << *it << " ";   //dereferencing
    }
    std::cout "\n";
    
    auto it = str3.begin();    //not redeclaration
    while(it != end) {
        std::cout << *it << " ";   //dereferencing
        it++;
    }
    std::cout << std::endl;
    
    std::swap(str13) //specializes the std::swap algorithm
    
    std::cout << "##################### RAW_STRINGS ######################" << std::endl;
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
    std::cout << "##################### IO ######################" << std::endl;
    
    //operator<<       //used with streams
    
    //operator>>       //used with streams
    
    std::getline(stream& s, std::string& line);  //reads line up to '\n' or EOF into string
    
    std::cout << "##################### -STD=C++14 ######################" << std::endl;
    //std::to_string();
    
    //std::operator""s
    using namespace std::string_literals; // Required for operator""s
    auto s1 = "Hello"s;   // Creates std::string
    auto s2 = "World";    // This is a const char*
    
    void foo(std::string s);
    foo("hello");  // Implicit conversion (may not be optimal)
    foo("hello"s); // Explicitly std::string, avoiding ambiguities
    
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
     //gloabal operator<=>
     
     */
    str20 <=> "some string data";
    
    std::cout << "##################### -STD=C++23 ######################" << std::endl;
    std::string str23_1 = "standard string data with some meaning";
    std::string str23_2 = "another string data with some meaning";
    
    str23_1.compare();
    
    str23_2.append_range();
    str23_2.replace_with_range();
    str23_2.resize_and_overwrite();
    return 0;
}

