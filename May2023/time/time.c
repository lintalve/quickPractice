/*
This quick practice isdedicated to time in c. Below I wrote functions
of the library <time.h>

clock();            //how much processor time has been used by this process
difftime();         //compute the difference between two times
mktime();           //Convert a struct tm into a time_t
time();             //Get the current calendar time
timespec_get();     //Get a higher resolution time, probably now
asctime();          //Return a human readable form of struct tm
ctime();            //Return a human readable form of time_t
gmtime();           //Convert a calendar time into a UTC broken-down time
localtime();        //Convert a calendar time into a broken-down local time
strftime();         //Formated date and time output

time_t time;              //special c type to hold time in integer seconds
                          //is used to hold absolute liniar time since 1st January 1970

struct tm                 //struct of ints to hold broken time to years, months, weeks, 
                          //hours, minutes, seconds. Also has int for bool 
                          //compensated daytime, probably to know if there's summer time

struct timespec ts;       //struct representing time in seconds and nanoseconds

clock_t clock;            //some opac type, holds return value of clock()
                          //number of CPU clock ticks..

*/
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>          //this is system header with precious sleep(int sec) function

int main(void){

    struct timespec ts;
    ts.tv_sec = 0;
    ts.tv_nsec = 50000000;

    int i=-30;
    //while(i<40 && i>-32){                    // does the fucker evaluates condition twice??   NO
    while(i<40){                    // does the fucker evaluates condition twice??
        double x = sin((i * 1.0)/2);
                          

        nanosleep(&ts, &ts);
        printf("this is i %lf\n", x);
        //usleep(100000);      //feels like nanoseconds, this function is deprecated
        i++;
    }
    printf("CPU time is %lf\n", clock()/((double)CLOCKS_PER_SEC));
    printf("CPU clock ticks are %lu\n", clock());                   //notice the lu, specifier for sizes
    return 0;

}