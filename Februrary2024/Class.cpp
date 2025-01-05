#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class SomeClass {
public:
  float x = 1.2;
  float y = 2.45;
  char someChar;
  void print(void) {
    return;                 //empty return
  }
};

struct SomeStruct {
  int someInt;
};


//------------------------------Main------------------
int main(void) {
  cout << "d is "<<'\n';
  cout << "d is "<<'\n';
  SomeClass someClass = someClass;
  someClass.x = 1234.6345;
  someClass.someChar = 'H';

  string someString = "some string";


  int theInt = 234;
  float theFloat = 3.14;
  int someHex = 0x1A12;

  printf("theInt is printing as digit %d\n", theInt);
  printf("theFloat is pinting as float %4f\n", theFloat);
  printf("someHex is printing as hex %x or %X \n", someHex, someHex);
  printf("accessing float member of the class someClass.x %f\n ", someClass.x);
  printf("accessing char member of the class someClass.someChar %d\n", someClass.someChar);
  printf("accessing char member of the class someClass.someChar %c\n", someClass.someChar);
  printf("accessing string  %s\n", someString); //for some reason doesn't work

  return 0;
}
