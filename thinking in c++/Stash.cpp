//: C04:CppLib.cpp {0}
// Áèáëèîòåêà â ñòèëå Ñ, ïåðåâåäåííàÿ íà Ñ++
// Îáúÿâëåíèå ñòðóêòóðû è ôóíêöèé
#include "Stash.h"
#include <iostream>
#include <cassert>
using namespace std;
// Êîëè÷åñòâî ýëåìåíòîâ, äîáàâëÿåìûõ ïðè óâåëè÷åíèè ðàçìåðà áóôåðà:
const int increment = 100;

void Stash::initialize(int sz) {
	size = sz;
	quantity = 0;
	storage = 0;
	next = 0;
}

int Stash::add(const void* element) {
	if (next >= quantity)	// Â áóôåðå åñòü ñâîáîäíîå ìåñòî?
		inflate(increment);
	// Ñêîïèðîâàòü ýëåìåíò â ñëåäóþùóþ ñâîáîäíóþ ïîçèöèþ áóôåðà:
	int startBytes = next * size;
	unsigned char* e = (unsigned char*)element;
	for (int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1);	// Èíäåêñ
}

void* Stash::fetch(int index) {
	// Ïðîâåðêà èíäåêñà
	assert(0 <= index);
	if (index >= next)
		return 0;	// Ïðèçíàê êîíöà
	// Óêàçàòåëü íà çàïðàøèâàåìûé ýåëåìåíò:
	return &(storage[index * size]);
}

int Stash::count() {
	return next;	// Êîëè÷åñòâî ýëåìåíòîâ â Stash
}

void Stash::inflate(int increase) {
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	int oldBytes = quantity * size;
	unsigned char* b = new unsigned char[newBytes];
	for (int i = 0; i < oldBytes; i++)
		b[i] = storage[i];	// Êîïèðîâàíèå ñòàðîãî áóôåðà â íîâûé
	delete []storage;		// Îñâîáîæäåíèå ñòàðîãî áóôåðà
	storage = b;	// Ïåðåâîä óêàçàòåëÿ íà íîâûé áóôåð
	quantity = newQuantity;
}

void Stash::cleanup() {
	if (storage != 0) {
		cout << "freeing storage" << endl;
		delete []storage;
	}
} ///:~
