//: EX02:Ex05.cpp
// �������� ��������� Fillvector.cpp ���, ����� ������ ���������� � ��������
// ������� (�� ��������� � ������)
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("Ex05.cpp");
	string line;
	while ( getline(in, line) )
		v.push_back(line);	// ��������� ������ � ����� �������
	// ��������� �����:
	for (int i = v.size() - 1; i >= 0; i--)
		cout << i << ": " << v[i] << endl;
} ///:~