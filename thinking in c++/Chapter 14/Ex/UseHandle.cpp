//: EX06:UseHandle.cpp
// �������� ���� Handle.h, Handle.cpp � UseHandle.cpp (��. ����� ����� 5) ���,
// ����� � ��� ������������� ������������ � �����������.
#include "Handle.h"

int main() {
	Handle u;
	u.initialize();
	u.read();
	u.change(1);
	u.cleanup();
} ///:~
