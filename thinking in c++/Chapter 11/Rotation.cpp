//: C03:Rotation.cpp {0}
// ����������� ���� ����� � ������
#include "printBinary.h"
#include "Rotation.h"
#include <iostream>
using namespace std;

// ��������������� ������:
#define PR(STR, EXPR) \
cout << STR; printBinary(EXPR); cout << endl;

unsigned char rol(unsigned char val) {
	int highbit;
	if (val & 0x80)	// 0x80 - �����, � ������� ���������� ������ ������� ���
		highbit = 1;
	else
		highbit = 0;
	// ����� ����� (������� ��� ���������� ������ 0):
	val <<= 1;
	// ���� �������� ���� � ������� ���:
	val |= highbit;
	
	return val;
}

unsigned char ror(unsigned char val) {
	int lowbit;
	if (val & 1) // �������� �������� ����
		lowbit = 1;
	else
		lowbit = 0;
	val >>= 1;	// ����� ������ �� ���� �������
	// ���� �������� ���� � ������� ���:
	val |= (lowbit << 7);
	return val;
} ///:~
/*
int main() {
	unsigned int getval;
	unsigned char a, b;
	cout << "Enter a number between 0 and 255: ";
	cin >> getval; a = getval;
	PR("a in binary: ", a);
	cout << "Enter a number between 0 and 255: ";
	cin >> getval; b = getval;
	PR("Initial a = ", a);
	PR("Initial b = ", b);
	PR("ror(a) = ", ror(a));
	PR("ror(b) = ", ror(b));
	PR("rol(a) = ", rol(a));
	PR("rol(b) = ", rol(b));
}
*/