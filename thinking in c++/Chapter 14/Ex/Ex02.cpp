//: EX06:Ex02.cpp
// �������� � ����� �� ���������� 1 ����������, ������� ����� ��������
// ��������� � ������.
#include <iostream>
using namespace std;

class Simple {
	int i;
public:
	Simple();
	Simple(int value);
	void print();
	~Simple();
};

Simple::Simple() {
	cout << "Simple::Simple()" << endl;
}

Simple::Simple(int value) {
	i = value;
	cout << "Simple::Simple(int i)" << endl;
}

void Simple::print() {
	cout << "Class Simple hidden value is " << i << endl;
}

Simple::~Simple() {
	cout << "Simple::~Simple()" << endl;
}

int main() {
	Simple s;
} ///:~
