//: C03:VoidPointer.cpp
int main() {
	void* vp;
	char c;
	int i;
	float f;
	double d;
	// ��������� void* ����� ��������� ����� ������ ����:
	vp = &c;
	vp = &i;
	vp = &f;
	vp = &d;
} ///:~