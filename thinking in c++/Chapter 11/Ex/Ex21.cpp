//: EX03:Ex21.cpp
// �������� ������ �������� string � ��������� ������ ������� ��������. 
// �������� ���������� ������� � ����� for.
#include <iostream>
using namespace std;

int main() {
	string s[10];
	for (int i = 0; i < 10; i++) {
		cout << "Enter string: "; cin >> s[i];
	}
		
	cout << "Entered values are: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << s[i] << endl;
	}
} ///:~