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

int main(void){
    time_t now;             //it is integer
    printf("size of this time_t type is %zu\n\n", sizeof(time_t));   //8 bytes, typedeefed unsigned long int
    now = time(NULL);
    printf("This are the seconds %ld since the EPOCH\n", now);   
                                  //if it is printed  with %ld, typedefed unsigned long int
    time(&now);                   //you can get it like so too
    printf("This are the seconds %ld since the EPOCH\n", now); 
    printf("This are the seconds %lu since the EPOCH\n", now); 
    printf("\n");
    printf("%s\n", ctime(&now));     //pay attension to the pointer

    struct timespec ts = {    //this means it is declared in time.h header
        .tv_sec = 435,
        .tv_nsec = 987
    };
    typedef struct timespec timespec;
    timespec* tsptr = &ts;

    int timespec_base;
    timespec_base = timespec_get(tsptr, TIME_UTC);
    printf("this are the absolute time seconds %ld\n", ts.tv_sec);
    printf("this are the billionths of that second %ld\n", ts.tv_nsec);
    printf("this are base of timespec_get() %d\n\n", timespec_base);     //1, it prints 1
    
    
    //OK, now that we've got our time now, let's convert it to UTC broken down time
    struct tm local = {         //it is defined in a header as a struct
        .tm_sec = 45,                        //like a class, defined the type, not a varible
        .tm_min = 15,                       // and here we are initializing a variable of
        .tm_hour = 9,                        //type struct tm..    
        .tm_mday = 5,
        .tm_mon = 3,
        .tm_year = 123,
        //.tm_wday = 3,           //it is set by the localtime();
        //.tm_yday = 6, 
        .tm_isdst = 0
        //.tm_gmtoff

    };
    struct tm* tmptr = &local;    
    tmptr = localtime(&now);
    printf("this are the current seconds %i\n", tmptr->tm_sec);                 //this are the seconds of struct tm
    printf("this are the current minutes %i\n", tmptr->tm_min);            //this are the minutes of struct tm
    printf("this are the current hours %i\n", tmptr->tm_hour);             //this are the hours of struct tm
    printf("this is the current day of the current month %i\n", tmptr->tm_mday);   //this is the day of the month of struct tm
    printf("this is the current month %i\n", tmptr->tm_mon);                       //this is the month of struct tm
    printf("this is the current year %i\n", tmptr->tm_year);
    printf("this is the current day of the current week %i\n", tmptr->tm_wday);
    printf("this is the current day of the current year %i\n", tmptr->tm_yday);
    printf("this is the day saving flag %i\n", tmptr->tm_isdst);
    printf("this is the GMT offset in seconds %li\n", tmptr->tm_gmtoff);
    printf("this is thetime zone %s\n", tmptr->tm_zone);
    printf("\n");

    struct tm utc;
    struct tm* utcptr = &utc;
    utcptr = gmtime(&now);
    printf("this are the utc seconds %i\n", utcptr->tm_sec);                 //this are the seconds of struct tm
    printf("this are the utc minutes %i\n", utcptr->tm_min);            //this are the minutes of struct tm
    printf("this are the utc hours %i\n", utcptr->tm_hour);             //this are the hours of struct tm
    printf("this is the utc day of the current month %i\n", utcptr->tm_mday);   //this is the day of the month of struct tm
    printf("this is the utc month %i\n", utcptr->tm_mon);                       //this is the month of struct tm
    printf("this is the utc year %i\n", utcptr->tm_year);                       //year since 1900
    printf("this is the utc day of the current week %i\n", utcptr->tm_wday);
    printf("this is the utc day of the current year %i\n", utcptr->tm_yday);
    printf("this is the day saving flag %i\n", utcptr->tm_isdst);
    printf("this is the GMT offset in seconds %li\n", utcptr->tm_gmtoff);
    printf("this is thetime zone %s\n", utcptr->tm_zone);
    printf("\n");
    //alrighty, here we go, these are the local and mgt time structs tms
    //lets convert it back to time_t format and print that out
    time_t sometime;
    struct tm sometime_tm = {         //it is defined in a header as a struct
        .tm_sec = 45,                        //like a class, defined the type, not a varible
        .tm_min = 15,                       // and here we are initializing a variable of
        .tm_hour = 9,                        //type struct tm..    
        .tm_mday = 5,
        .tm_mon = 3,
        .tm_year = 123,
        //.tm_wday = 3,           //it is set by the localtime();
        //.tm_yday = 6, 
        .tm_isdst = 0,
        //.tm_gmtoff
        //.tm_zone

    };
    sometime = mktime(&sometime_tm);
    printf("this are the seconds made from sometime_tm %lu\n", sometime);
    //and now we can compute the difference of now and some time
    double dif;
    dif = difftime(now, sometime);
    printf("this is the difference %lf\n", dif);
    
    double time_res = time_resolution();
    printf("detailed time is %lf\n", time_res);
    //printf("size of long double is %zu\n", sizeof(long double));   //16 bytes

    //and finally let's excercise printing time with the last 3 functions of the bunch
    const time_t* time_ptr = &now;
    const struct tm* broken_down_time = tmptr;
    printf("this is string ctime() vesion of the time_t %s\n", ctime(time_ptr));
    printf("this is string asctime() vesion of the struct tm  %s\n", asctime(broken_down_time));
    char string[SIZE];
    time_t now2 = time(NULL);
    strftime(string, sizeof(string), "%c", localtime(&now2));   //weirdly prits to a string passed by value
    puts(string);     //prints a string without shit
    
    return 0;
}