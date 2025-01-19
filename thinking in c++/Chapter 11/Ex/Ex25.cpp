//: EX03:Ex25.cpp
// ���������� ���������� ���� float. �������� �� �����, ��������� ��� � ����
// unsigned char � ��������� ��������� �� unsigned char. ��� ������ ����� ���������
// � ����������� [] ����������� �������� ������� �� ���������� ����
// float � ��� ������ ������� printBinary(), ������������ � ���� �����, ��������
// �������� ��������� ������ ���������� (�������� ������ ����������� �� 0 �� sizeof(float)-1).
// �������� �������� float � ���������� ����������� �� ���������� ������������� �����
// (������ ���� float �������� � ����������� �������).
#include "../printBinary.h"
#include <iostream>
using namespace std;

int main() {
	float a;
	float* a_ptr = &a;
	unsigned char* uchar_ptr = reinterpret_cast<unsigned char*>(a_ptr);
	cout << "Enter float value: "; cin >> a;
	for (int i = 0; i < sizeof(float); i++, uchar_ptr++) {
		printBinary(*uchar_ptr);
		cout << " ";
	}
} ///:~