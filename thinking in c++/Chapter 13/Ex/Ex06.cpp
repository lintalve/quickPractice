//: EX08:Ex06.cpp
// �������� ����������� ������ char � ���������� �������� ���� �� ���������.
#include <iostream>

int main() {
	const char hello[] = {'c', 'o', 'n', 's', 't', '\0'};
	
	hello[0] = 'p';
	*hello = 'p';
	
	std::cout << hello << std::endl;
} ///:~
