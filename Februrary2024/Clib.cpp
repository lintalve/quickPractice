
//: C04:CLib.cpp {0}
// Ðåàëèçàöèÿ áèáëèîòåêè â ñòèëå Ñ
// Îáúÿâëåíèå ñòðóêòóðû è ôóíêöèé:
#include "CLib.h"
#include <iostream>
#include <cassert>
using namespace std;
// Êîëè÷åñòâî ýëåìåíòîâ, äîáàâëÿåìûõ ïðè óâåëè÷åíèè ðàçìåðà áóôåðà:
const int increment = 100;

void initialize(CStash* s, int sz) {
	s->size = sz;
	s->quantity = 0;
	s->storage = 0;
	s->next = 0;
}

int add(CStash* s, const void* element) {
	if (s->next >= s->quantity)	// Â áóôåðå åñòü ñâîáîäíîå ìåñòî?
		inflate(s, increment);
	// Ñêîïèðîâàòü ýëåìåíò â ñëåäóþùóþ ñâîáîäíóþ ïîçèöèþ áóôåðà:
	int startBytes = s->next * s->size;
	unsigned char* e = (unsigned char*)element;
	for (int i = 0; i < s->size; i++)
		s->storage[startBytes + i] = e[i];
	s->next++;
	return(s->next - 1);	// Èíäåêñ
}

void* fetch(CStash* s, int index) {
	// Ïðîâåðêà èíäåêñà:
	assert(0 <= index);
	if (index >= s->next)
		return 0;	// Ïðèçíàê êîíöà
	// Óêàçàòåëü íà çàïðàøèâàåìûé ýëåìåíò:
	return &(s->storage[index * s->size]);
}

int count(CStash* s) {
	return s->next;	// Êîëè÷åñòâî ýëåìåíòîâ â CStash
}

void inflate(CStash* s, int increase) {
	assert(increase >0);
	int newQuantity = s->quantity + increase;
	int newBytes = newQuantity * s->size;
	int oldBytes = s->quantity * s->size;
	unsigned char* b = new unsigned char[newBytes];
	for (int i = 0; i < oldBytes; i++)
		b[i] = s->storage[i];	// Êîïèðîâàíèå ñòàðîãî áóôåðà â íîâûé
	delete [](s->storage);		// Îñâîáîæäåíèå ñòàðîãî áóôåðà
	s->storage = b;		// Ïåðåâîä óêàçàòåëÿ íà íîâûé áóôåð
	s->quantity = newQuantity;
}

void cleanup(CStash* s) {
	if (s->storage != 0) {
		cout << "freeing storage" << endl;
		delete []s->storage;
	}
} ///:~
