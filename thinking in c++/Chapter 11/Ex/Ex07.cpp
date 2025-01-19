//: EX03:Ex07.cpp
// �������� ��� �������: ������ ������ �������� �������� ���� string*, � ������ -
// �������� ���� string&. ������ ������� ������ �������� ������� ������
// string ����� ��������. � ������� main() �������� � ���������������
// ������ string, �������� ��� ����������, ����� ��������� ������ �� ����
// ������� � �������� ����������.
#include <iostream>
using namespace std;

void f1(string* s) {
	*s = "I'm in f1 function";
	cout << *s << endl;
}

void f2(string &s) {
	s = "I'm in f2 function";
	cout << s << endl;
}

int main() {
	string s = "I'm in main function";
	cout << s << endl;
	f1(&s);
	cout << s << endl;
	f2(s);
	cout << s << endl;
} ///:~