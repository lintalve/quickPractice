//: EX06:Ex10.cpp
// �������� ����� ��� ������������� � ��������� � ���, ��� � ��������� �����
// ��������� ������� ������������� �� ���������. ����� ���������� ��� ������
// �����������, �������� ��� ������ ���������� ��������, � ���������� ����� 
// ��������������� ���������. ���������, ��� ����������.
#include <iostream>
using namespace std;

class A {
	int a;
public:
	A(int value);
	void seta(int value);
	void print();
};

A::A(int value) {
	a = value;
}

void A::seta(int value) {
	a = value;
}

void A::print() {
	cout << a << endl;
}

int main() {
	A a;
	a.seta(5);
	a.print();
} ///:~
