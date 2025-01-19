//: C08:Ex15.cpp
// � ��������� ConstReturnValues.cpp ��������������� �������� �����������
// � �������, ���������� ������. ����������, ����� ��������� ������ ����������

class X {
	int i;
public:
	X(int ii = 0);
	void modify();
};

X::X(int ii) { i = ii; }

void X::modify() { i++; }

X f5() {
	return X();
}

const X f6() {
	return X();
}

void f7(X& x) { // �������� �� ������������� ������
	x.modify();
}

int main() {
	f5() = X(1);	// ����� -- ������������� ������������ ��������
	f5().modify();	// �����
//  Ex15.cpp:31: error: invalid initialization of non-const reference of 
//  type 'X&' from a temporary of type 'X'
//  Ex15.cpp:24: error: in passing argument 1 of `void f7(X&)'
//!	f7(f5());		// �������������� ��� ������
// ������ ����������
//  Ex15.cpp:36: error: passing `const X' as `this' argument of 
//  `X& X::operator=(const X&)' discards qualifiers
//!  f6() = X(1);
//  Ex15.cpp:39: error: passing `const X' as `this' argument of 
//  `void X::modify()' discards qualifiers
//!  f6().modify();
//  Ex15.cpp:42: error: invalid initialization of non-const reference 
//  of type 'X&' from a temporary of type 'const X'
//  Ex15.cpp:24: error: in passing argument 1 of `void f7(X&)'
//!f7(f6());
} ///:~
