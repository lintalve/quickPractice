//: EX09:Ex06.cpp
// ��������, ��� ��� ������������� ������� �� ��������� ������������ 
// ���������� ����������.
#include "Ex06.h"

inline void X::f1() {
	std::cout << "i'm inline funciton f1() from separate header file (Ex06.h): " << a << std::endl;
}

int main() {
	X x;
	x.f1();
}
