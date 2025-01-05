#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUS");
    int d = 0;
    int dd = 0;
    cout << "Введите делимое : "; cin >> d;
    cout << "Введите делитель : "; cin >> dd;
    int i = 0;
    int d1 = d;
    int dd1 = dd;
    while (d1 > 0)
    {
        d1 -= dd1;
        i++;
        if (d1 < 0)
        {
            i--;
        }
    }
    cout << "Частное от деления : " <<i<< endl;
    ////////////////////////////////////////////
    int ost = 0;

    while (d>0)
    {
        ost = (d -= dd);
        if (d < 0)
            ost += dd;
    }
    cout << "Остаток : " << ost << endl;
    //////////////////////////////////////
    int proverka = (dd * i) + ost;
    cout << "Делитель (" << dd << ") * Частное от деления(" << i << ") + Остаток(" << ost << ") = " << (dd * i) + ost << endl;
    return 0;
}
