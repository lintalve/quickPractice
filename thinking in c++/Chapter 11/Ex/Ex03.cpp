//: EX03:Ex03.cpp
// �������� ���������, ������� ��� ������ ����� while ������ ����� �� �����������
// ����� (cin) � ������ string. ���� while ������ ���� �����������,
// � ����� �� ���� �������������� �� ������� break. ������ ����������� ����� ��� 
// ������ ����� ������ if ������� "������������" �� ����� �����,
// ������� ����� ������������ �������� switch � �������� �������� ������
// (�� ����� ��������, ��� ����� ������������������ ������� �������� �������
// ������ ����������������; ��� ����� ������ ��� ���������� � ������ � ������������
// �������������). ������ ������ ������ case ������ ���������� �����-������ �����������
// ���������. �������������� �������� "������" ����� � �� �������������. �����
// ������, ����� ����� ������ �������� � ���������� ���������. ��������� ������
// ��������� � ���������� ������������� ����������� ���� ������� � ������ �� �����
// (����� ��� �� �������� ������� ������ ������, �������������� ������ � ��������
// ������� ���������).
#include <iostream>
using namespace std;

int main() {
	string word;
	int criteria;
	
	cout << "Enter fruit name or quit for exit" << endl;
	
	while (true) {
		cout << "Enter the word" << endl;
		cin >> word;
		if (word == "orange")
			criteria = 1;
		else if (word == "apple")
			criteria = 2;
		else if (word == "peach")
			criteria = 3;
		else if (word == "peanapple")
			criteria = 4;
		else if (word == "quit")
			break;
			
		switch (criteria) {
			case 1:
				cout << "Do you want orange?" << endl;
				break;
			case 2:
				cout << "Do you want apple?" << endl;
				break;
			case 3:
				cout << "Do you want peach?" << endl;
				break;
			case 4:
				cout << "Do you want peanapple?" << endl;
				break;
		}
	}
} ///:~