//: EX09:Ex18.cpp
// �������� ������ FIELD() ���, ����� � ��� ������������� �������� �������� index. 
// �������� �����, ����� �������� �������� ������ FIELD(). �������� � ����� �������
// ��� ������� ���� �� �������. �������� ������� main() ��� ������������ ������.
#include <iostream>

#define INT_FIELD(a) int_##a
#define FIELD(a) static int int_##a = a

FIELD(1); FIELD(2);
FIELD(3); FIELD(0);

void showVarAt(int index) {
	switch (index) {
		case 1: std::cout << INT_FIELD(1) << std::endl; break;
		case 2: std::cout << INT_FIELD(2) << std::endl; break;
		case 3: std::cout << INT_FIELD(3) << std::endl; break;
		default: std::cout << INT_FIELD(0) << std::endl; break;
	}
}

int main() {
	for (int i = 0; i < 10; i++)
		showVarAt(i);
}
