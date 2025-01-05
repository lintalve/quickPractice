#include <stdio.h>

void func(int){};   //my first nameless argument

int main(void){
   
   int i = 6;
   int ii = 9;
   int iii = 0x7fff;  //32767
   int iiii = 2147483647;  
   int i0 = 32768;
   float f = 5.64f;
   float ff = 4.1264f;
   float fff = 4.1245664f;
   double d = 63.38745;
   double dd = 75.345;
   double ddd = 15.37562344536086;
   bool shit = true;  //native support, nice

   const int constInt0 = 2147483648;

   short sh0 = 32;
   sh0 = static_cast<short>(iiii);     //loss of data due to short being small type
   printf("this is sh0 %d\n", sh0); 

   short sh1 = static_cast<short>(i0);
   printf("this is sh1 %d\n", sh1);  //loss of data immediately after 32767

   unsigned char ch0 = 255;   //maximum value, 2^16  
   signed char ch1 = 127;
   printf("this is ch0 %d\n", ch0);
   ch1 = static_cast<char>(d);
   printf("this is ch1 now %d\n", ch1); // looks safe enough, floors the value
   char ch2 = 0;
   shit = ch2;   //implicit
   printf("this is shit now %d\n", shit);   //there is no bool specifier 
/////////////////////////////CONST_CAST////////////
   
   //! i0 = const_cast<int>(constInt0);  // you can't use const_cast on non pointer
   //! int* = &constInt0;  //this is a const int* type of value
   const int* i1Ptr = &constInt0;
   const int* const i2Ptr = &constInt0;
   int* i4Ptr = (int*)&constInt0;  //old style, works as well
   //! int* i5Ptr = static_cast<int*>(&constInt0); //static_cast can't cast away const nature
   i0 = static_cast<int>(constInt0);  //very interresting, usin static_cast to convert
                                      //constant into variable int 
   int* i0Ptr = const_cast<int*>(&constInt0);  //removing the const nature of a pointer
   int* i3Ptr = const_cast<int*>(i2Ptr);  //again removing const nature of the pointer

   long someLong0 = 235523.5097l;
   long* long0Ptr = &someLong0;
   //! long* long1Ptr = const_cast<long*>(&constInt0);  //const_cast can only
                                                        //remove const, it can't
                                                        //change the type
   volatile int k = 0;
   int* u = const_cast<int*>(&k); //volatile I still need to learn
   return 0;
}