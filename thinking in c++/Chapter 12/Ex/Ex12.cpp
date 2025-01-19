//: EX05:Ex12.cpp
// ��������� ������� ������ Hen �� ���������� 6 � ��������� Stack. ����������
// � �������� ��� ������� (�������� ������� Hen::print(), ���� ��� �� ����
// ������� �����).
#include "Stack2.h"
#include "Hen.h"
#include <iostream>
using namespace std;

int main() {
	Stack stack;
	Hen* hen;
	
	stack.initialize();
	for (int i = 0; i < 5; i++)
		stack.push(new Hen());
	
	while ((hen = (Hen*)stack.pop()) != 0) {
		hen->print();
		delete hen;
	}
	stack.cleanup();
} ///:~
