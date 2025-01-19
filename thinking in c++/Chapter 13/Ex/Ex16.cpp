//: EX08:Ex16.cpp
// � ��������� ConstPointer.cpp ��������������� �������� ����������� � �������,
// ���������� ������. ����������, ����� ��������� ������ ����������.

void t(int*) {}

void u(const int* cip) {
//  Ex16.cpp:8: error: assignment of read-only location
//!	*cip = 2;	// ������ -- ����������� ��������
	int i = *cip;	// ����� -- ����������� ��������
//  Ex16.cpp:11: error: invalid conversion from `const int*' to `int*'
//! int* ip2 = cip;	// ������ -- �� ���������
}

const char* v() {
	// ����������� ������ ������������ ����������� �������:
	return "result of function v()";
}

const int* const w() {
	static int i;
	return &i;
}

int main() {
	int x = 0;
	int* ip = &x;
	const int* cip = &x;
	t(ip);	// �����
//  Ex16.cpp:30: error: invalid conversion from `const int*' to `int*'
//	Ex16.cpp:30: error:   initializing argument 1 of `void t(int*)'
//!	t(cip);	// ������
	u(ip);	// �����
	u(cip);	// ���� �����
//  Ex16.cpp:35: error: invalid conversion from `const char*' to `char*'
//! char* cp = v();	// ������
	const char* ccp = v();	// �����
//  Ex16.cpp:38: error: invalid conversion from `const int* const' to `int*'
//!	int* ip2 = w();	// ������
	const int* const ccip = w();	// �����
	const int* cip2 = w();	// �����
//	Ex16.cpp:42: error: assignment of read-only location
//!	*w() = 1;	// ������
} ///:~
