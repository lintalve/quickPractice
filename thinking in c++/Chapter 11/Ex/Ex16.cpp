//: EX03:Ex16.cpp
// �������� ��������� � ������������� �����, ���������� ������ 
// �������� ������. �������� ���������� ����� ���� � �������� ��� �����,
// ��������������� ��������� ������, � ����� for
#include <iostream>
using namespace std;

enum COLORS {
	RED,
	GREEN,
	BLUE,
	YELLOW,
	BLACK,
	BROWN,
	WHITE
};

int main() {
	for (COLORS my_color = RED; my_color <= WHITE; my_color = static_cast<COLORS>(my_color + 1))
		cout << my_color << endl;
} ///:~