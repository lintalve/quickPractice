//: C07:AnonymousUnion.cpp
int main() {
	union {
		int i;
		float f;
	};
	// ��������� � ������ ���������� ��� �������� ����������:
	i = 12;
	f = 1.22;
} ///:~
