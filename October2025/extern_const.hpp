
#ifndef EXTERN_CONST
#define EXTERN_CONST


extern const int someConstInt;   //gives me linkage error
/*
 extern keyword changes the internal linkage, each cpp file becomes a translation unit
 with defined someConstInt = 234;
 (linker error if in header)
 */


//extern const int someConstInt;   //It’s semantically redundant, but harmless.
//extern const int someConstInt; //this works why???


const int myConstInt = 543;



extern const int aConstInt; //Is defined in a separate cpp file for use in that file
                            //you can't bring it in the file that you include THIS header in.

//return const int doesn't ERROR if you assign this return to a non const int identifier
const int intFunction(int integer = 45);

#endif //EXTERN_CONST
