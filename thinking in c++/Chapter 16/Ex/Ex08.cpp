//: EX07:Ex08.cpp
// �������� ����� SuperVar ���, ����� ���� ��� vartype ���������� � ���������
// #ifdef, ��� ������� � ��������������� �������. ������������ ��� vartype
// � ������� �������� ������������ (��� ����������) � �������� �������
// print() ���, ����� �� ����������� �������� vartype, ������������ 
// ����������� ��������
#include <iostream>
using namespace std;

#define VARTYPE

enum VarType {
	character,
	integer,
	floating_point
};	// ����������� ����

class SuperVar {
	#ifdef VARTYPE
	VarType vartype;
	#endif
	union {		// ��������� �����������
		char c;
		int i;
		float f;
	};
public:
	SuperVar(char ch);
	SuperVar(int ii);
	SuperVar(float ff);
	#ifndef VARTYPE
	void print(VarType vartype);
	#else
	void print();
	#endif
};

SuperVar::SuperVar(char ch) {
	#ifdef VARTYPE
	vartype = character;
	#endif
	c = ch;
}

SuperVar::SuperVar(int ii) {
	#ifdef VARTYPE
	vartype = integer;
	#endif
	i = ii;
}

SuperVar::SuperVar(float ff) {
	#ifdef VARTYPE
	vartype = floating_point;
	#endif
	f = ff;
}

#ifndef VARTYPE
void SuperVar::print(VarType vartype) {
#else
void SuperVar::print() {
#endif
	switch (vartype) {
	case character:
		cout << "character: " << c << endl;
		break;
	case integer:
		cout << "integer: " << i << endl;
		break;
	case floating_point:
		cout << "float: " << f << endl;
		break;
	}
}

int main() {
	SuperVar A('c'), B(12), C(1.44F);
	#ifndef VARTYPE
	A.print(character);
	B.print(integer);
	C.print(floating_point);
	#else
	A.print();
	B.print();
	C.print();
	#endif
} ///:~
