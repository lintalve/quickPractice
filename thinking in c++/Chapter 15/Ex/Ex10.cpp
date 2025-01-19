//: EX02:Ex10.cpp
// �������� ������ vector<float> � �������� � ���� 25 ������������ �����, ���
// � ���������� ��������. ��������� ������ ����� � ������� � ��������� ���������
// � �������� �������� �������. �������� ���������� ������� �� � ����� ����������
// � �������.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> v;
	float value;
	for (int i = 0; i < 25; i++) {
		value = i + i * 0.1;
		v.push_back(value);
	}
	cout << "Results before squaring: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] * v[i];
	cout << "Results after squaring: ";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
} ///:~