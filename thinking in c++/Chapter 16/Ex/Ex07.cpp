//: C06:Stack3Test.cpp
// �������� ����� ������ ������ Stack �� ����� 6 � ������������� �� ���������
// � ������ �������������, � ���������� �������� ���������� ������ ����������
// �� ������� � ������ ����� �������. ����������� ������ ���������� ��������
// ������� � �������� ������ ��������� � ����. ������������� ����� � 
// �������� �������� string.
#include "Stack3.h"
#include "../../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	requireArgs(argc, 1);	// �������� - ��� �����
	ifstream in(argv[1]);
	assure(in, argv[1]);
	void* string_buffer[100];
	int string_buffer_count = 0;
	string line;
	// ������ ����� � ���������� ����� � �����:
	while (getline(in, line))
		string_buffer[string_buffer_count++] = (void*)(new string(line));
	
	Stack textlines(string_buffer, string_buffer_count);
	
	// ���������� ����� �� ����� � �����:
	string* s;
	while ((s = (string*)textlines.pop()) != 0) {
		cout << *s << endl;
		delete s;
	}
} ///:~
