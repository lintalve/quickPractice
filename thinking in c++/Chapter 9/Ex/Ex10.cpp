//: EX09:Ex10.cpp
// �������� ������������� ��� Hue � ���������� red, blue � yellow. ����� ��������
// ����� Color, ���������� ���������� ���� Hue � �����������, ������������� Hue
// �������� ����������� ���������. ���������� ��� Hue ������� ������� get � set. 
// ��� ������� ������ ���� ��������������.
#include <iostream>

enum Hue {
	red,
	blue,
	yellow
};

class Color {
	Hue hue;
public:
	Color() : hue() {}
	Color(Hue hue): hue(hue) {}
	inline Hue getHue() { return hue; }
	inline void setHue() { this->hue = hue; }
	inline void print() {
		switch (this->getHue()) {
			case red: std::cout << "red" << std::endl; break;
			case blue: std::cout << "blue" << std::endl; break;
			case yellow: std::cout << "yellow" << std::endl; break;
			default: std::cout << "unknown" << std::endl; break;
		}
	}
};

int main() {
	Color color;
	color.print();
}
