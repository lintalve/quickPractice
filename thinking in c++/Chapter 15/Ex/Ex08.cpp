//: EX02:Ex08.cpp
// �������� ������ vector<float> � �������� � ���� 25 ������������ ����� 
// � ����� for. �������� ���������� �������.
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<float> v;
	for (int i = 0; i < 25; i++)
		v.push_back(i + i * 0.1);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ", ";
	cout << endl;
} ///:~