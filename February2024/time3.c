/*
This quick practice isdedicated to time in c. Below I wrote functions
of the library <time.h>

time_t time(time_t*);                       //Get the current calendar time
clock_t clock(void);                        //how much processor time has been used by this process
int timespec_get(struct ts*, int base);     //Get a higher resolution time, probably now
double difftime(time_t, time_t);            //compute the difference between two times
struct tm* localtime(const time_t*);        //Convert a calendar time into a broken-down local time
struct tm* gmtime(const time_t*);           //Convert a calendar time into a UTC broken-down time
time_t mktime(struct tm*);                  //Convert a struct tm into a time_t
asctime(const struct tm*);                  //Return a human readable form of struct tm
ctime();                                    //Return a human readable form of time_t
strftime();                                  //Formated date and time output

time_t time;              //special c type to hold time in integer seconds
                          //is used to hold absolute liniar time since 1st January 1970

struct tm                 //struct of ints to hold broken time to years, months, weeks, 
                          //hours, minutes, seconds. Also has int for bool 
                          //compensated daytime, probably to know if there's summer time
struct tm

struct timespec ts;       //struct representing time in seconds and nanoseconds

struct timespec ts{     
    time_t tv_sec;
    long tv_nsec;
}
struct tm {
	int	tm_sec;		       //seconds after the minute [0-60] 
	int	tm_min;		       //minutes after the hour [0-59] 
	int	tm_hour;	       //hours since midnight [0-23] 
	int	tm_mday;	       //day of the month [1-31] 
	int	tm_mon;		       //months since January [0-11] 
	int	tm_year;	       //years since 1900 
	int	tm_wday;	       //days since Sunday [0-6] 
	int	tm_yday;	       //days since January 1 [0-365] 
	int	tm_isdst;	       //Daylight Savings Time flag 
	long	tm_gmtoff;	   //offset from UTC in seconds 
	char*   tm_zone;	   //timezone abbreviation 
};

*/
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>          //this is system header with precious sleep(int sec) function
#define SIZE 128

long double time_resolution(){
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    double nsec = ((double)ts.tv_nsec)/1000000000;
    printf("long int nsec is %li\n", ts.tv_nsec);
    printf("double nsec is %lf\n", nsec);
    double sec = (double)(int)ts.tv_sec;
    double time_resolution = sec + nsec;
    return time_resolution;
}
long long int fibonaci(long long int n){
    if(n<=1) return n;
    return fibonaci(n-1) + fibonaci(n-2);
}

int main(void){
    long long int number = 50L;
    long long int fib = fibonaci(number);
    printf("the fibonaci number is %lli", fib);
    return 0;
}