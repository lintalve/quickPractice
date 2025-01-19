//: EX09:Ex16.cpp
// �������� ���������, ���������� ������ string � ��������� ��������� ������.
// �������� � ��� ���� for, ������� ��� ������ �������� ������ ������� �� string
// ���� ������ � �������� ����� ���������� string � ������� �a����� DEBUG().
#include <iostream>
#include <string>
#include "../../require.h"

#define DEBUG(x) std::cout << #x " = " << x << std::endl

int main(int argc, char* argv[]) {
	requireArgs(argc, 1);
	std::string entered_string = argv[1];
	std::cout << "Now we will clean entered string. Please, press Enter to stop." << std::endl;

	while (std::cin.get() != '\n') {
		entered_string.erase(entered_string.length() - 1, 1);
		DEBUG(entered_string);
	}
}
VMsys123
