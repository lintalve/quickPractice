//: EX07:Ex02.cpp
// �������� ����� Message � �������������, ���������� ���� �������� ���� 
// string �� ��������� �� ���������. ���������� �������� ���������� string;
// ����������� ������ ������ ����������� �������� ����������� ���������
// ���������� ���������� string. �������� � ������ Message ��� �������������
// ������� print(): ������ ������� ������ ���������� ��� ���������� � ��������
// ���������, ���������� � �������, � ������ ������� ������ �������� ��������
// string � �������� ��� ���������� ������ � ���������� �� �������. ���������
// �������� ����� ������ ������ ����, � ������� ������������ ������������?
#include <string>
#include <iostream>
using namespace std;

class Message {
	string message;
public:
	Message(string = "dumb message");
	~Message();
	void print();
	void print(string another_message);
};

Message::Message(string incoming_message) {
	message = incoming_message;
}

Message::~Message() {}

void Message::print() {
	cout << message << endl;
}

void Message::print(string another_message) {
	cout << message << " " << another_message << endl;
}

int main() {
	Message m1;
	Message m2("This is another object.");
	m1.print(); m1.print("Call with arguments");
	m2.print(); m2.print("Call with arguments");
}
