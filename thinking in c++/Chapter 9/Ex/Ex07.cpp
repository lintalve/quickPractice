//: EX09:Ex07.cpp
// �������� �����, ���������� ������ char. �������� � ���� ������������� �����������,
// ������� ���������� ����������� ������������ ������� � memset() ��� �������������
// ������� ���������, ���������� � ��������� ("�� ���������"). ����� �������� � ����� 
// ������������� ������� print() ��� ������ ���� �������� �������.
#include <iostream>
#include <cstdlib>
#include <string>

class X {
	char* array;
	int length;
public:
	X(const int length, const int init = '-') { 
		this->length = length;
		array = new char[length];
		memset(array, init, length);
	}
	~X() { delete array;}
	inline void print() { 
		for (int i = 0; i < length; i++)
			std::cout << array[i];
		std::cout << std::endl; 
	}
};

int main() {
	X x(10, 'A');
	x.print();
}
