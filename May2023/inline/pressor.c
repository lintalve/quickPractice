#include "system.h"
#include <stdio.h>

/*
this file demonstrates the use of inbuilt definitions like
    __DATE__    string date of the compilation,
    __TIME__    string time of the compilation,
    __FILE__    string name of the file compiled,
    __LINE__    integer line number
    __func__    string name of the func
    __STDC__    
    __STDC_VERSION__  string value of current version of c
*/
     


#ifdef MACOS             
#include <unistd.h>
void printFuncName(){
    printf("%s\n", __func__);       //works, prints 'printFuncName'
}

#endif  //MACOS





int main(void){
#ifdef __DATE__    //the string value of compilation date
    int secs = 2;
    puts("starting sleep");
    sleep(2);
    printf("printing %s %s after %i seconds\n", __DATE__, __TIME__, secs);  
    printf("this line number is %s\n", __FILE__);              
    printf("this line number is %i\n", __LINE__);   
    printFuncName();       

    printf("this is %ld\n", __STDC_VERSION__);      //long integer is guessed from the numeral 29384756L, L

#endif //__DATE__

    return 0;
}