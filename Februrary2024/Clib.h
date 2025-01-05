
//: C04:CLib.h
// Çàãîëîâî÷íûé ôàéë äëÿ áèáëèîòåêè â ñòèëå C.
// Ñòðóêòóðà CStash ÿâëÿåòñÿ àíàëîãîì ìàññèâà.
// íî ñîçäàåòñÿ íà ñòàäèè âûïîëíåíèÿ

typedef struct CStashTag {
	int size;		// Ðàçìåð êàæäîãî ýëåìåíòà
	int quantity;	// Êîëè÷åñòâî ýëåìåíòîâ
	int next;		// Ñëåäóþùèé ïóñòîé ýëåìåíò
	// Äèíàìè÷åñêè âûäåëÿåìûé áàéòîâûé ìàññèâ
	unsigned char* storage;
} CStash;

void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);
///:~
