#include "system.h"

#ifdef WIN32
//#include <windows.h>   //using windows
#elif MACOS 
#include <unistd.h>
#endif

#include <cstdio>


int main(void){


#ifdef WINDOWS10
    puts("using windows 10 specific system calls\n");
#endif //WINDOWS10

#ifdef WIN33   //this is beautiful, look how the 
    puts("using windows 10 specific system calls\n");
#endif //WIN33

#ifndef WIN32
    puts("using windows 10 specific system calls\n");
#endif //WIN32

#ifdef WIN32
    puts("using memory under 2 Gigs \n");
#endif //WIN32

#if MACOS == 0
    puts("This is not a MacOS\n");
    puts("Not using MacOS cpecific system calls\n");
#elif MACOS == 2
    puts("This is the MacOS Ventura \n");
#elif MACOS == 1
    puts("This is the MacOS Mojave");
    puts("Using functions 1.2.4");
#else
    puts("This is some other bullshit entirely\n");
#endif //MACOS 1

    //if(WIN32){ puts("Win32\n");}    //expects an expression, and evidentlty it's not
                                      //probably because
    if(MACOS == 1) puts("This is MacOS");  //this is if(1 == 1) after preprocessor

    return 0;
}