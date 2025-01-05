#include <stdio.h>

//////////////CHAR////////////////////  8bit      1 byte   1 byte of machine type
char someChar0 = 'c';   // 1 byte 8 bit wide smallest type from -128 to 0 to 127
char someChar1 = 'b';   // can be printed as an integer digit
char someChar2 = 120;   //
char someChar3 = -128;  // illustrates signed behabiour by default
char someChar4 = 127; //starts to count from lowest -127, adding 150-127
                     // up to 199   overflowed
signed char someSignedChar0 = 'a';  // explisit signed char
signed char someSignedChar1 = 97;  //if printed with %c gives an 'a'
unsigned char someUnsignedChar0 = 129;  //explisit unsigned char is from 0 to 255
unsigned char someUnsignedChar1 = 255;  //because of zero, there's a zero in the first bit

unsigned char myChar0 = 255;   //would be 256, but there's a 0 to begin with

///////////////////////SHORT(short int)//////////////////////////// 16bit   2bytes  word of machine type

short someShort0 = 32767; // signed by default from -32768 to 0 to 32767 -2^15
short int someShort1 = -32768;
signed short someShort2 = 234;
signed short int someShort3 = -234;
unsigned short someUnsignedShortInt = 1234;   // from 0 to 65535
unsigned short int someUsignedShortInt = 2424;  // same thing from 0 to 65535 2pow15

short int myShort0 = 98;

////////////////////INT/////////////////////////// 32 bit  4 bytes   double word of machine type
int someInt0 = -2147483648;   // signed by default from -2147483648 to 2147483647 '-' and 2^31
signed  someInt1 = 2147483647; // explisitly signed from -2147483648 to 2147483647 '-' and 2^31
signed int someInt2 = -2147483648;// explisitly signed from -8147483648 to 2147483648 '-' and 2^31
unsigned  someInt3 = 4294967295;  // from 0 to 4,294,967,295    2^32-1
unsigned int someInt4 = 4294967295;  // from 0 to 4,294,967,295    2^32-1

/////////////////////////LONG///////////////////////32 bit  4 bytes   double word of machine type
long someLong0 = -2147483648;   // signed by default from -2147483648 to 2147483648 '-' and 2^31
long int someLong1 = 2147483647;  //signed by default from -2147483648 to 2147483648 '-' and 2^31
signed long someLong2 = -2147483648;  // explisitly signed from -2147483648 to 2147483647 '-' and 2^31
signed long int someLong3 = 2147483647;  // explisitly signed from -2147483648 to 2147483647 '-' and 2^31
unsigned long someLong4 = 4294967295;  // from 0 to 4,294,967,295    2^32-1
unsigned long int someLong5 = 4294967295;  // from 0 to 4,294,967,295    2^32-1

///////////////////////////LONG LONG///////////////// 64 bit  8 bytes quadword of machine type
long long someLongLong0 = -9223372036854775807;
long long int someLongLong1 = 9223372036854775807;
signed long long someLongLong2 = -9223372036854775807;
signed long long int someLongLong3 = 9223372036854775807;
unsigned long long someLongLong4 = 1844674407370955161L;
unsigned long long int someLongLong5 = 1844674407370955161L;

/////////////////////////////FLOAT////////////////
float someFloat0 = 0.4618749465f;
float someFloat1 = -0.1235566165415f;
float someFloat2 = -0.1235566165415f;
float someFloat3 = -0.1235566165415f;

/////////////////////////////DOUBLE////////////////
double someDouble0 = 0.65442236423666;

////////////////////////////LONG DOUBLE///////////// 98 bits  12 bytes
long double someLongDouble0 = 654.81683213786854;

//-----------------------MAIN-------------------------------
int main(int argc, char const *argv[]) {
	///////////////////////////////Short/////////////////////////////////////
	printf("someChar0 is printing with %c\n", someChar0);  //character specifier
	printf("someChar1 is printing with %d\n", someChar1);  //signed decimal integer
	printf("someChar2 is printing with %d\n", someChar2);
	printf("someChar3 is printing with %d\n", someChar3);
	printf("someChar4 is printing with %d\n", someChar4);
	printf("someUnsignedChar1 is printing with %d\n\n\n", someUnsignedChar1);

	//printf("someSignedChar0 is printing with %c\n", someSignedChar0);
	//printf("someSignedChar0 is printing with %c\n", someSignedChar1);
	//printf("unsigned myChar0 is printing with %d\n", myChar0);
	///////////////////////////////Short/////////////////////////////////////
	printf("--------------SHORTS---------------------------\n");
	printf("someShort0 is an int that half the int size %hi\n", someShort0);   //short signed like imul
	printf("someShort1 is an int that half the int size %hi\n", someShort1);
	printf("someShort2 is an int that half the int size %hu\n\n\n", someShort2);   //short unsigned hu
	printf("someShort2 is an int that half the int size %hu\n\n\n", someUnsignedShortInt);   //short unsigned hu
	////////////////////////////INT//////////////////////////////////
	printf("--------------INT---------------------------\n");
	printf("someInt0 is an int that half the int size %i\n", someInt0);
	printf("someInt1 is an int that half the int size %i\n", someInt1);
	printf("someInt3 is an int that half the int size %i\n", someInt3);
	printf("size_t size of an Int %lu\n", sizeof(int));
	printf("size_t size of a Long %lu\n", sizeof(long));
	printf("size_t size of a LongLongInt %lu\n\n\n\n", sizeof(long long int));

	//////////////////////////////////LONG/////////////////////////////
	printf("--------------------------LONG---------------------------\n");
	printf("long is surprisingly same as int, someLong is printed with %ld\n", someLong0);
	printf("long is surprisingly same as int, someLong is printed with %ld\n", someLong1);
	printf("long is surprisingly same as int, someLong is printed with %ld\n", someLong2);
	printf("long is surprisingly same as int, someLong is printed with %ld\n", someLong3);
	printf("long is surprisingly same as int, someLong is printed with %lu\n", someLong5);  //long unsigned???

//////////////////////////////////LONG LONG////////////////////////////
	printf("--------------------------LONG LONG---------------------------\n");
	printf("long long is double size of an int and someLongLong0 is printed as %lli\n", someLongLong0);
	printf("long long is double size of an int and someLongLong1 is printed as %llu\n", someLongLong1);
	printf("long long is double size of an int and someLongLong2 is printed as %lld\n", someLongLong2);

//////////////////////////////////FLOAT////////////////////////////
	printf("--------------------------FLOAT---------------------------\n");
	printf("finally float someFloat0 is printed with %f\n", someFloat0);
	printf("finally float someFloat0 is printed with %lf\n", someFloat0);
	printf("finally float someFloat0 is printed with %g\n", someFloat1);
	printf("finally float someFloat0 is printed with %G\n", someFloat1);
	printf("finally float someFloat0 is printed with %e\n", someFloat2);
	printf("finally float someFloat0 is printed with %e\n", someFloat2);
	printf("finally float someFloat0 is printed with %a\n", someFloat3);
	printf("finally float someFloat0 is printed with %a\n", someFloat3);

//////////////////////////////////DOUBLE////////////////////////////
	printf("--------------------------DOUBLE---------------------------\n");
	printf("size_t size of double is %zu bytes\n", sizeof(double));   // %zu unsigned decimal
	printf("double someDouble0 is printed with %.20lf\n", someDouble0);  // 20 digit after dot '.'
	printf("double someDouble0 is printed with %.20lg\n", someDouble0);
	printf("double someDouble0 is printed with %le\n", someDouble0);
	printf("double someDouble0 is printed with %la\n", someDouble0);

//////////////////////////////////LONG DOUBLE////////////////////////////
	printf("--------------------------LONG DOUBLE---------------------------\n");
	printf("size_t size of long double is %lu bytes\n", sizeof(long double));   // %zu unsigned decimal

  return 0;
}
