//: C08:PointerAssignment.cpp
int d = 1;
const int e = 2;
int* u = &d;		// ����� -- d �� �������� ����������
//! int* v = &e;	// ������ -- � �������� ����������
int* w = (int*)&e;	// �����, �� ��� ������ �����
int main() {} ///:~
