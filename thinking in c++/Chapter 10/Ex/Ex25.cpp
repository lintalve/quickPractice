//: EX04:Ex25.cpp
// ��������� ���������� 25, �� ������ ������������� "���������" ��������
// � ������� ��������� �� ������ ���������.
#include <iostream>
using namespace std;

struct Link {
	int number;
	Link* next_link;
	void build_list(int count);
	void print();
};

void Link::build_list(int count) {
	
		Link* new_link = new Link;
		new_link->next_link = 0;
		new_link->number = number + 1;
		next_link = new_link;
		
		if (count != 0)
			new_link->build_list(count - 1);
}

void Link::print() {
	cout << number << endl;
	if (this->next_link != 0)
		this->next_link->print();
}

int main() {
	Link l;
	l.number = 0;
	l.build_list(10);
	l.print();
}