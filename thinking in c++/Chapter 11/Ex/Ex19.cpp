//: EX03:Ex19.cpp
// �������� ��������� ArrayAddress.cpp ���, ����� ��� �������� � �������
// ����� char, long, int, float � double
#include <iostream>
using namespace std;

int main() {
	char a[10];
	cout << "sizeof(int) = " << sizeof(int) << endl;
	for (int i = 0; i < 10; i++)
		cout << "&a[" << i << "] = "
		<< (long)&a[i] << endl;
} ///:~