//: EX09:Ex20.cpp
// �������� ���������, ���������� ��� ��������� ��������� ������: ����� int � ��� 
// �����. ��� ������ ������� require.h ��������� � ���, ��� ��������� �������� 
// ���������� ���������� ����������, �������� int ��������� � ��������� �� 5 �� 10,
// � ���� ������� �����������.
#include <iostream>
#include "../../require.h"

int main(int argc, char* argv[]) {
	requireMinArgs(argc, 2);
	require(atoi(argv[1]) >= 5);
	require(atoi(argv[1]) <= 10);
	
	char* file_name = argv[2];
	std::ifstream in(file_name);
	
	assure(in, file_name);
}
