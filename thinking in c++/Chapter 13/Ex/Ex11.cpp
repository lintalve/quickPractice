//: C08:Ex11.cpp
// ������� ����������� � ��������� ������ ������� PointerAssignment.cpp
// � ����������, ����� ������ ������ ��� ����������
int d = 1;
const int e = 2;
int* u = &d;		// ����� -- d �� �������� ����������
// Ex11.cpp:7: error: invalid conversion from `const int*' to `int*'
//!	int* v = &e;	// ������ -- � �������� ����������
int* w = (int*)&e;	// �����, �� ��� ������ �����
int main() {} ///:~
