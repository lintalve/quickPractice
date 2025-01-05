//01.05.17 20.10 Частное от деления и остаток используя только сложение и вычитание
//olewasl
#include <iostream>
 
using namespace std;
 
int main()
{
    int del=0;  //Делимое
    int dlt=0;  //Делитель
    int nRep=0; //Частное
    int booLdel=0;//определение отрицательного делимого
    int booLdlt=0;//определение отрицательного делителя
    cout<<"Enter delimoe : ";
    cin>>del;
    if(del<0)
    {
        del=del*(-1); //если число меньше 0,умножаем на -1, производим вычисления над числами больше 0
        booLdel=1;  //если делимое меньше 0, то присваиваем 1
    }
    else;
    do
    {
    cout<<"Enter delitel : ";
    cin>>dlt;
    if(dlt==0)
        cout<<"Delitel cant be equal 0\n";
    }while(dlt==0);
    if(dlt<0){
        dlt=dlt*(-1);   //если число меньше 0,умножаем на -1, производим вычисления над числами больше 0
        booLdlt=1;     //если делитель меньше 0, то присваиваем 1
    }
    else;
 
    while(del>=0 && del>=dlt)
    {
        del=del-dlt;
        nRep++;  //количество вычитаний и есть частное
    }
//если оба числа либо больше либо меньше нуля, знак не меняем
    if((booLdel==1 && booLdlt==1)||(booLdel==0 && booLdlt==0))
    {
        cout<<"Chastnoe : "<<nRep<<" "<<endl;
        if(del!=0)
        cout<<"Ostatok : "<<del;
        else;
    }
  //если одно из чисел отрицательное,меняем знак
    else
    {
        cout<<"Chastnoe : "<<nRep*(-1)<<" "<<endl;
        if(del!=0)
        cout<<"Ostatok : "<<del;
        else;
    }
    return 0;
};
