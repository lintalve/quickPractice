//: EX05:Ex06.cpp
// �������� ����� Hen, ���������� � ��� ��������� ����� Nest. � ������ Nest
// ���������� ��������� ����� Egg. ������ ����� ������ ��������� ������� display().
// � ������� main() �������� ��������� ������� ������ � �������� ������� display()
// ��� ���� �������.
#include <iostream>
using namespace std;

class Hen {
public:
	class Nest {
	public:
		class Egg {
		public:
			void display();
		};
		
		void display();
	};
	
	void display();
};

void Hen::display() {
	cout << "Hen.display()" << endl;
}

void Hen::Nest::display() {
	cout << "Hen.Nest.display()" << endl;
}

void Hen::Nest::Egg::display() {
	cout << "Hen::Nest::Egg::display()" << endl;
}

int main() {
	Hen h;
	Hen::Nest n;
	Hen::Nest::Egg e;
	
	h.display();
	n.display();
	e.display();
} ///:~
