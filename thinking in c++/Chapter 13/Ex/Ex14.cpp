//: EX08:Ex14.cpp
// �������� �������, ������� �������� �������� ���� float �� ��������.
// ������ ������� ������� �������� �� ������� const float& � � ����������,
// ��������� ������, ��������� � ���, ��� �������� �������� ����������
#include <iostream>

void print(float value) {
	const float& another_value = value;
//	Ex14.cpp:9: error: assignment of read-only reference `another_value'
//!	another_value = 5.5;
	std::cout << "Value is " << value << std::endl;
}

int main() {
	print(3.3);
} ///:~
