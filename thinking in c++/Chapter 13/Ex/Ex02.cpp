//: EX08:Ex02.cpp
// ��������� � ���, ��� ����������� � � C++ ������������� ��-������� 
// �������� � �����������. �������� ���������� ��������� � ����������� ��
// � ���������� ����������� ���������; �������������� ��������� � �������
// � � �++
#include <stdio.h>

const int a = 1, b = 2, c = 3;
char buf[a + b + c];

int main() {
	printf("Size is: %d\n", sizeof(buf));
	printf("Size of a: %d\n", sizeof(a));
	printf("Address of a: %p\n", &a);
	//std::cout << sizeof(buf) << std::endl;
	//std::cout << "Done..." << std::endl;
}
