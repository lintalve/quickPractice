//: EX07:Ex05.cpp
// �������� ������� � ����� ����������� � �������� �� �� main(). �����
// ������������ ���� �������� � "�����������" (�� ���� �������� ��� ��������������)
// � ����������, ��������� �� ��� ���� ����� � main().
#include <iostream>

void someFunction(int first, int) {
	std::cout << "Soem Function" << std::endl;
}

int main() {
	someFunction(1, 2);
}
