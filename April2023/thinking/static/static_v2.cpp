#include <stdio.h>
//no user headers for this one

const char* someGlobalString = "this is someString from static_v2.cpp";  //const char*!!! const!! 

char incChar(char c){         //global name, extern or not, has external linkage
    return c++;
}


extern short incFunc(short c = 0){          //32767
    static short stShort;       //has static memory, value preserved between calls
    if(c) {
        stShort = c;
        return stShort;
    }else{
        //return ++stShort;     //increments before return it
        return stShort++;       //returns and increments afterwards
    }
}

static long longFunc(long l = 0){       //default parameter, must be at the and of parameter list
    extern long someLong;           //not static!!
                                //defined else where 
    return ++someLong;

}

extern long longFunc(){
    extern long someLong;  //not static!!
                           //defined else where 
    return ++someLong;

}