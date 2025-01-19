//: EX09:Ex04.cpp
// �������� ��� ���������� ������� � ������� f1() � f2(). �������� ������� f1()
// �������������, � ������� f2() - ���������������. ��� ������ �����������
// ������� clock() �� ���������� <ctime> �������� ����� ������ � ���������� �������
// � ��������, ����� �� ���� ������� �������� �������. ��������, ��� ��������� ����������� 
// ������ ������ ������� �������� ����������� �������� � �����.
#include <iostream>
#include <ctime>

static const int ARRAY_SIZE = 10000000;
int array[ARRAY_SIZE];

void f1() {
	for (int i = 0; i < ARRAY_SIZE; i++)
		array[i] = i;
}

inline void f2() {
	for (int i = 0; i < ARRAY_SIZE; i++)
		array[i] = i;
}

int main() {
	clock_t start_f1 = clock();
	f1();
	clock_t end_f1 = clock();
	std::cout << "f1() time: " << (double)(end_f1 - start_f1)/CLOCKS_PER_SEC << std::endl;
	
	clock_t start_f2 = clock();
	f2();
	clock_t end_f2 = clock();
	std::cout << "f2() time: " << (double)(end_f2 - start_f2)/CLOCKS_PER_SEC << std::endl;
}
