//: EX02:Ex07.cpp
// �������� ���������� ����� �� �������. ����� ������ ������ ������ ���������
// ������ �����, ���� ������������ ������ ������� Enter.
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("Ex07.cpp");
	string line;
	char ch;
	while ( getline(in, line) )
		v.push_back(line);	// ��������� ������ � ����� �������
	// ��������� �����:
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
		while (cin.get() != '\n'); 
	}
} ///:~