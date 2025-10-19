#include <string>
#include <iostream>
#include <format>
#include <print>
#include <algorithm>

int main(int argc, const char* argv[]) {
    
    std::string str2;
    if(str2.empty()) {
        str2 += "some data";
    }
    std::cout << "##################### MODIFYING #######################" << std::endl;
    
    std::string str3 = "the new data that have beed read from file";
    std::print("the length is {}, and now it's {} and now it's {} and it reads {}\n", str3.length(),
               [](std::string st) mutable { st.erase(); return st.length();} (str3),
               str3.append(" another data").length(), str3);
    
    //so str.erase() //erases all chars and sets the length to 0;
    
    
    //iterator str3.erase(iterator first, iterator last);
    std::string::iterator it = str3.erase(str3.begin() + 8, str3.begin() + 14);  //returns iterator pointing to the char after deleted (15th as it were)
    //std::distance(iterator start, iterator finish);
    std::print("{}\n", str3.substr(0, std::distance(str3.begin(), it))); //should return "the new "
    std::print("{}\n", str3);  //should return "the new hat have been ..."
    
    //std::string substr(size_t pos = 0, size_t count = npos) const;  //npos means end position
    //str.append() reurns *this of the string appended with an argument
    //str+=  does the same
    using namespace std::string_literals;  //using namespace std::string_literals
    //using namespace std::string_literals;  //introduced in c++14
    std::print("{}\n", "some string"s += " prints fine");
    
    //str.push_back()
    //str.pop_back()     //doesn't return
    
    //let's try to reverse a string with append;
    std::string str4 = "the new data that"s + "have beed read from file"s;
    std::print("{}\n", str4);
    std::string reversed;  //length 0
    for(auto it = str4.rbegin(); it != str4.rend(); it++ ) {
        std::cout << *it << " ";
        //reversed.append(std::to_string(*it));   //converts integer value of char probably
        reversed.push_back(*it);   //should push back a char, needless to say, increments length();
    }
    std::print("\n{}\n", reversed);
    
    std::string str5 = "qwerty";
    std::string str6;
    for(int i=0; i<str5.length(); i++) {
        str6.push_back(str5.at(str5.length() - i - 1));      //very nice code
    }
    std::print("\n{}\n", str6);   //ytrewq
    std::cout << "##################### <algorithm> #######################\n";
    
    /*
     // Replace a substring with another string
     std::string& replace(size_t pos, size_t count, const std::string& str);

     // Replace a substring with a C-string
     std::string& replace(size_t pos, size_t count, const char* s);

     // Replace a substring with a character repeated n times
     std::string& replace(size_t pos, size_t count, size_t n, char c);

     // Replace using iterators (range replacement)
     std::string& replace(iterator first, iterator last, const std::string& str);

     */
    
    return 0;
}
