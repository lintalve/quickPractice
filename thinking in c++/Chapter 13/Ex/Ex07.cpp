//: EX08:Ex07.cpp
// �������� � ����� ���������� ������� ��������� (extern const); ��������
// � ���� ������� main(), ������� ������� �������� extern const. ��������
// ����������� ������� ��������� � ������ �����, �������������� � �����������
// ��� �����.
#include "Ex070.h"
#include <iostream>

extern const int current_year;

int main() {
	//current_year = 2014;
	print();
	std::cout << "Current year is " << current_year << std::endl;
}
