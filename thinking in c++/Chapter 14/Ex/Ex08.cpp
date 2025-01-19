//: EX06:Ex08.cpp
// ����������� ���������� ������������� ��� �������� ������� ��������
// string. �������� ������ Stack ��� �������� �������� string � � �����
// ���������� �������� �������; ��� ������ �������� ������� ������ string ������
// ���������� � ����. ����� ��������� ������� string �� ����� � ������� ��
// ��������.
#include <iostream>
#include "../Stack3.h"
using namespace std;

int main() {
	string s_array[] = { string("Green"), string("Blue"), 
						 string("Red"), string("Black"), 
						 string("Yellow"), string("Brown"), 
						 string("Pink"), string("Magenta") };
	
	Stack stack;
	
	for (int i = 0; i < sizeof(s_array) / sizeof(*s_array); i++)
		stack.push(&s_array[i]);
	
	string* line;
	while ((line = (string*)stack.pop()) != 0)
		cout << *line << endl;
		
} ///:~
