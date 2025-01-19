//: EX05:Ex15.cpp
// �������� ����� StackOfInt (����, ���������� �������� int) c �����������
// �������� "���������� ����"; �������������� ��������� ������, ���������������
// ������������ ��� �������� ���������, ������ ���� ������ � ������ 
// StackImp. ���������� ��� ������ StackImp: � ����� ������ ���� ������������
// ������ int ������������� ������, � � ������ - vector<int>. ����������
// ������������ ������ �����, ����� ��� �� �������� ������������ � ����������
// ������� � ������ ������. �������� ��������: ��������� StackImp �� �����������
// �������� � ��������� StackOfInt.h
#include "StackOfInt.h"
#include <iostream>
using namespace std;

int main() {
	const int size = 15;
	StackOfInt stackOfInt;
	stackOfInt.initialize(size);
	for (int i = 0; i < size; i++)
		stackOfInt.push(i);
	
	int return_value;
	while ((return_value = stackOfInt.pop()) != NULL)
		cout << return_value << endl;
} ///:~
