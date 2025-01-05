#include <stdio.h>
#include <limits.h>


short int aaa= 5;  //короткие инты выводятся через %d
long int bbb = 1354654354;  //длинные инты выводятся через %ld

double ccc = 0.123546; // глобальная переменная

unsigned char tuffle = sizeof(ccc);   //глобальная переменная



int main() {

    int b = sizeof(aaa);
    printf("We'll do it\n" );
    printf("%03d,\t %d", aaa, b);
    printf("%f\n", ccc);

    //--------------from the book---------------//
    printf("size of short int is %d bytes\n\n", sizeof(short int) );
    ////-----------%ld----is-for-long-integers----
    printf("long int bbb is %9ld and size of %d bytes\n", bbb, sizeof(bbb) );
    printf("size of long int is %d\n", sizeof(bbb) );
    printf("size of double is %d\n", sizeof(double) );
    printf("size of char is %d\n", sizeof(char) );
    //-------------------------------------------------
    printf("size of ccc is %d\n", tuffle );

    printf("%d\n", SHRT_MIN);  /*подгруженное из limits.h SHRT_MIN выводит
                                дно short int'a сразу в мейн*/
    printf("in header <limits.h> there is a cap for long int => %ld\n", LONG_MAX);
    printf("and amout of RAM for it is (sizeof() directly in main) %d bytes\n", sizeof(LONG_MAX));
    return 0;
}
