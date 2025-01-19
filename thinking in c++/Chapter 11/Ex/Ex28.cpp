//: EX03:Ex28.cpp
// �������� �������, ������� �������� ��������� �� ������ double � ������
// ����� �������; ������� ������ �������� �������� ���� ��������� �������.
// �������� ������ double, ������������������ ��� �������� ������ � �������� ������ 
// ��� ������ �������. ��� ������ ��������� reinterpret_cast ������������ 
// ��������� ����� ������� � unsigned char* � ��������� ������� ����� �������
// �������� 1 (���������� ������ � double ������ ������������ ���������� sizeof).
// ����� ��������� ���������� �������. ��� �� �������, ������ ��������� �� ���� 
// ��������� �������� 1.0?
#include <iostream>
using namespace std;

void printArray(double* array, int array_size) {
	cout << "Array: ";
	for (int i = 0; i < array_size; i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	double d[] = {0, 0, 0, 0, 0};
	unsigned char* uchar_ptr = reinterpret_cast<unsigned char*>(d);
	printArray(d, 5);
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < sizeof(double); j++)
			uchar_ptr[i * sizeof(double) + j] = 1;
			
	printArray(d, 5);
} ///:~