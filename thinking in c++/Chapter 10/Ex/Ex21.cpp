//: EX04:Ex21.cpp
// ��� ���� �������� � ���� �����, �++ ������������� ������� ��� ��������
// ���, ��� ������������ ���������� ��������� typedef. �� �� ����� ��������
// ��� ������������� ����� � �����������. �������� ��������� ��������� ��� 
// ������������ ����� �����.
#include <iostream>
using namespace std;

struct Struct1 {
};

union Union1 {
};

enum Enum1 {
};

int main() {
	cout << "sizeof(Struct1) = " << sizeof(Struct1) << endl;
	cout << "sizeof(Union1) = " << sizeof(Union1) << endl;
	cout << "sizeof(Enum1) = " << sizeof(Enum1) << endl;
}