//: C05:Handle.cpp {0}
// ���������� ������-������������
#include "Handle.h"
#include "../require.h"

// ����������� ���������� Handle;
struct Handle::Cheshire {
	int i;
};

void Handle::initialize() {
	smile = new Cheshire;
	smile->i = 0;
}

void Handle::cleanup() {
	delete smile;
}

int Handle::read() {
	return smile->i;
}

void Handle::change(int x) {
	smile->i = x;
} ///:~
