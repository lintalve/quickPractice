//: EX08:Ex18.cpp
// � ��������� ConstTemporary.cpp ������� ����������� � ������, ����������
// ������. ����������, ����� ��������� ������ ����������
class X {};

X f() { return X(); }	// ����������� �� ��������

void g1(X&) {}			// �������� �� ������� ������
void g2(const X&) {}	// �������� �� ������ �� ���������

int main() {
	// ������: f() ������� ����������� ��������� ������:
	// Ex18.cpp:13: error: invalid initialization of non-const reference 
	// of type 'X&' from a temporary of type 'X'
	// Ex18.cpp:8: error: in passing argument 1 of `void g1(X&)'
//!	g1(f());
	// �����: g2 �������� ������ �� ���������
	g2(f());
} ///:~
