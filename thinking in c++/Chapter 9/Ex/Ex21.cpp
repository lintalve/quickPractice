//: EX09:Ex21.cpp
// �������� ���������, ������� ��� ������ ������� IFOPEN() ��������� ���� ��� ������� 
// �����. �������� �������� �� �������� ������� ifstream � ��� ���������.
#include "../../require.h"
#include <iostream>

#define IFOPEN(VAR,NAME) \
std::ifstream VAR(NAME); \
assure(VAR,NAME);

int main(int argc, char* argv[]) {
	requireMinArgs(argc, 1);
	IFOPEN(in, argv[1]);
}
