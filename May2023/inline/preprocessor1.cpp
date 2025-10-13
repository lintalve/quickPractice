#include "system.h"
#include <cstdio>


#ifdef WIN32
#include "windows.h"   //using windows
#define WINDOWS 2
#endif  //WIN32          //you have to use #endif before using another option


#ifdef MACOS             
#include <unistd.h>
#endif  //MACOS





int main(void){

#if MACOS == 0                                             // #if is used with definitions to a value 
    puts("This is not a MacOS\n");
    puts("Not using MacOS cpecific system calls\n");
#elif MACOS == 2                                           //now here we are using #elif legit
    puts("This is the MacOS Ventura \n");
#elif MACOS == 1
    puts("This is the MacOS Mojave");
    puts("Using functions 1.2.4");
#else                                                      //and #else as well, apropriate
    puts("This is some other bullshit entirely\n");
#endif //MACOS 1




    //if(WIN32){ puts("Win32\n");}    //expects an expression, and evidentlty it's not
                                      //probably because
    if(MACOS == 1) puts("This is MacOS");  //this is if(1 == 1) after preprocessor

#if 0
    puts("All this code");  //is effectively 
    puts("commented out");  //by #if 0 clause
#endif //0


#ifdef WIN32       //is the same
    puts("using memory under 2 Gigs");
#endif
#if defined WIN32  //as this
    puts("using memory under 2 Gigs");
#endif
#if defined(WIN32) //and this   NO SPACES
    puts("using memory under 2 Gigs");
#endif


#ifndef MACOS        //is the same
    puts("MACOS is not #defined");
#endif
#if !defined MACOS   //as this
    puts("MACOS is not #defined");
#endif
#if !defined(MACOS)  //and this
    puts("MACOS is not #defined");
#endif

//////////////////////////////////////
    int secs = 2;
    puts("starting sleep");
    sleep(2);
    printf("printing after %i seconds\n", secs);
    return 0;
}