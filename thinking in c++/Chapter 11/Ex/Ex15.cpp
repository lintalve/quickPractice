//: EX03:Ex15.cpp
// �������� ���������, ���������� ��� ������� string � ���������� int. ����������
// ��������� typedef ��� ����� ���������. �������� ��������� ���������, ���������������
// ��� ��� ���� ���������� � �������� �� ��������. �������� ����� ����������
// � ��������� ��� ����������-��������� �� ��� ����� ���������. �������� ��������
// ����� � ���������� � �������� �� ����� ���������.
#include <iostream>
using namespace std;

typedef struct user_card {
	int user_id;
	string user_name;
	string user_surname;
} user_card;

int main() {
	user_card michal;
	user_card* michel;
	michal.user_id = 1;
	michal.user_name = "Michal";
	michal.user_surname = "Alaskin";
	
	cout << "User card is following:" << endl;
	cout << michal.user_id << endl;
	cout << michal.user_name << endl;
	cout << michal.user_surname << endl << endl;
	
	michel = &michal;
	michel->user_id = 2;
	michel->user_name = "Michele";
	michel->user_surname = "Alaskina";
	cout << "User card is following:" << endl;
	cout << michel->user_id << endl;
	cout << michel->user_name << endl;
	cout << michel->user_surname << endl;
} ///:~
