//: EX02:Ex06.cpp
// �������� ��������� Fillvector.cpp ���, ����� ����� ������� ��� ��������
// ������� ������������ � ���� ������ (��������� ����� ��� ���� �� �����). 
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("Ex06.cpp");
	string line;
	while ( getline(in, line) )
		v.push_back(line);	// ��������� ������ � ����� �������
	// ����� � ���� ������
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
} ///:~