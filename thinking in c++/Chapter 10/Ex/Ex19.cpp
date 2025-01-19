//: EX04:Ex19.cpp
// �������� ��������� � ����������� ��������� ������ ������ ���������
// (��������� ���������). �������� ���������� � ����� ����������, �����
// �������� � ���������� � ��� �������. �������� ������� main() ��� 
// ������������ ����� �����.
#include <iostream>
using namespace std;

struct Person {
	struct PersonName {
		string name;
		string surname;
		string middlename;
		void print();
	};
	PersonName name;
	int age;
	char sex;
	void print();
};

void Person::PersonName::print() {
	cout << surname << " " << name << " " << middlename << endl;
}

void Person::print() {
	cout << "Age: " << age << endl;
	cout << "Sex: " << sex << endl;
}

int main() {
	Person p;
	p.name.name = "Maxim";
	p.name.surname = "Aliseenko";
	p.name.middlename = "Nikolaevich";
	p.age = 27;
	p.sex = 'M';
	
	p.name.print();
	p.print();
} ///:~
