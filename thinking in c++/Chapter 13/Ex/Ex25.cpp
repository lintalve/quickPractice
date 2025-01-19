//: EX08:Ex25.cpp
// � ������� Mutable.cpp ������� ����������� � ������, ���������� ������. 
// ����������, ����� ��������� ������ ����������.
class Z {
	int i;
	mutable int j;
public:
	Z();
	void f() const;
};

Z::Z() : i(0), j(0) {}

void Z::f() const {
// Ex25.cpp:15: error: increment of data-member `Z::i' in read-only structure
//!	i++;	// ������ -- ����������� �������
	j++;	// �����: mutable
}

int main() {
	const Z zz;
	zz.f();	// ������� �������� ����������� ������!
} ///:~
