//: EX04:Ex18.cpp
// �������� ������� � ���������� ���� char*. ������� ������ ����������� 
// (���������� new) �������� ������ ��� ������� char, ������ ��������
// ������������� ������� ����������� ����������� �������. ��������� ��������
// ��������������, ���������� ������� �� ��������� � ����������� ���������
// ������ ( �� �������� � ����������� ������� �������) � ������� ���������
// �� �����. ������������� ������� � main(), ������� �� ����������� ����������
// ������, ������� ��������� � ����� ������� ��� �������.
// �������� ��� ������ � ��� ���������, ����� ���������, ��� ��� ���������
// � ������ �������� ������. ���������� ������������ ������ ��� ������ 
// ��������� delete
#include <iostream>
#include <cstring>
using namespace std;

char* getString(char* incoming_string) {
	int incoming_string_length = strlen(incoming_string);
	char* returned_string = new char[incoming_string_length + 1];
	for (int i = 0; i < incoming_string_length; i++)
		returned_string[i] = incoming_string[i];
	returned_string[incoming_string_length] = '\0';
	return returned_string;
}

int main() {
	char* ch_array1 = getString("hello somebody");
	char* ch_array2 = getString(ch_array1);
	
	cout << "String 1: " << ch_array1 << endl;
	cout << "Address of 1st string: " << (long)static_cast<void*>(ch_array1) << endl;
	cout << "String 2: " << ch_array2 << endl;
	cout << "Address of 2nd string: " << (long)static_cast<void*>(ch_array2) << endl;
	
	delete[] ch_array1;
	delete[] ch_array2;
} ///:~
