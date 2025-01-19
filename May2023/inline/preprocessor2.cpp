#include "system.h"
#include <cstdio>


#if defined WINDOWS10
#include "windows10.h"   //using windows
void printOS(){
    puts("windows10 windows10 windows10");
}
#elif defined WIN32                         //legit code which doesn't work as expected
#include "windowsXP.h"   //using windows
void printOS(){                        //see???
    puts("windowsXP windowsXP windowsXP");
}
#elif defined(MACOS == 1)                   //legit code which doesn't work as expected
void printOS(){                        //see???
    puts("MacOS MacOS MacOS");
}
#endif  //WIN32         


#ifdef MACOS             
#include <unistd.h>
#endif  //MACOS





int main(void){
    int secs = 2;
    puts("starting sleep");
    sleep(2);
    printf("printing after %i seconds\n", secs);
    printOS();
#define GOATS
#ifdef GOATS
    puts("GOATS detected");
#undef GOATS                       //jucy directive to make GOATS no longer defined
#endif //GOATS

#if defined GOATS
    puts("NO GOATS detected");       //doesn't dim the light of it, but it works as expected
#endif



    return 0;
}