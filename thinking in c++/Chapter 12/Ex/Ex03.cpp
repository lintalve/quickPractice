//: EX05:Ex03.cpp
// ��������� ����� � ���������� ������������� �������, ������� ��������
// �������� �������� ���������� ������
#include <iostream>
using namespace std;

class A {
	int a;
	friend void seta(int x, A* a);
public:
	void print();
};

void A::print() {
	cout << "a = " << a << endl;
}

void seta(int x, A* a) {
	a->a = x;
}

int main() {
	A a;
	seta(5, &a);
	a.print();
} ///:~
