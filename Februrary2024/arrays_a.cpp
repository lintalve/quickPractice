#include <iostream>
#include <stdio.h>
using namespace std;

char char_array[8]; // чар аррей наверное для строк
//---------------------------------------------------

int main(int argc, char const *argv[]) {

    short int array[5];
    array[0] = 3;
    array[4] = 4;

    //array[-1] = 5;  //ошибка - попытка вывести содержимое
    //array[5] = 3;   //чужой ячейки, выделенной чужой программе

    for(char i =0; i < sizeof(double); i++){
        char_array[i] = 'i';
        //new_array[2] = 6;
        cout << char_array[i] <<"this is bullshit" <<endl;
    }// пиздец пиздец пиздец это мы с тобой пишем на си плюс плюс
//----------------------------
    int another_array[5];
    for (size_t i = 0; i < 5; i++) {
      another_array[i] = i;
      cout << another_array[i] << endl;
    }

    cout << array[0] << endl;
    cout << array[4] /*поинтер!!! указатель!!!*/ << "\tpointer!!" << endl;
  return 0;
}
