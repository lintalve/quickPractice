//: EX06:Ex03.cpp
// �������� � ����� �� ���������� 2 ���������� ���� int. �������� �����������
// ���, ����� ��� ������ ��� ����������� �������� int, �������� ��������
// ������ ����������� � ���������� ������. � �����������, � ����������
// ������ �������� �������� int � ����� ����������; ��� �������� �����������
// ������� �������� � ����������� ��������.
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
	cout << "i value is " << i << endl;
}

Simple::Simple(int value) {
	i = value;
	cout << "Simple::Simple(int i)" << endl;
	cout << "i value is " << i << endl;
}

void Simple::print() {
	cout << "Class Simple hidden value is " << i << endl;
}

Simple::~Simple() {
	cout << "Simple::~Simple()" << endl;
	cout << "i value is " << i << endl;
}

int main() {
	Simple s;
} ///:~
