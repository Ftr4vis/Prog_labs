#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stroka.h"
#include "DecStr.h"
#include "IdentStr.h"
#include <locale>

using namespace std;
extern "C" int __stdcall summa(int, int);
extern "C" char* __stdcall itostr(int);

int main() {
    setlocale(LC_ALL, "Russian");

    Stroka** pStr = new Stroka * [6];
    //динамический массив указателей на указатель типа Stroka*
    pStr[0] = new Stroka("Chicken");
    pStr[1] = new Stroka("Pizza");
    pStr[2] = new IdentStr("Wel");
    pStr[3] = new IdentStr("Come");
    pStr[4] = new DecStr("65521");
    pStr[5] = new DecStr("-1237");

    //Проверка Stroka
    Stroka* obj0 = dynamic_cast <Stroka*>(pStr[0]);
    obj0->Show();
    Stroka* obj1 = dynamic_cast <Stroka*>(pStr[1]);
    obj1->Show();
    *(obj1) = *(obj0);
    obj1->Show();
    Stroka R(*(obj0));
    R.Show();
    cout << "R.GetStr() ==> " << R.GetStr() << endl;
    cout << "R.GetLen() ==> " << R.GetLen() << endl;
    R.Clean();
    R.Show();

    //Проверка IdentStr
    IdentStr* obj2 = dynamic_cast <IdentStr*>(pStr[2]);
    IdentStr* obj3 = dynamic_cast <IdentStr*>(pStr[3]);
    *(obj2) = ~(*(obj2));
    obj2->Show();
    *(obj2) = *(obj3);
    obj2->Show();
    cout << "*(obj3)[2] ==> " << (*(obj3))[2] << endl;
    IdentStr X(*(obj2));
    X.Show();
    cout << "X < *(obj3) ==> " << (X < *(obj3)) << endl;
    IdentStr A("come");
    cout << "(*(obj3) < A) ==> " << (*(obj3) < A) << endl;
    IdentStr B("Well");
    cout << "(*(obj2) < B) ==> " << (*(obj2) < B) << endl;
    B = B + *(obj3);
    B.Show();
    B = B + "Back";
    B.Show();
    char C[] = "Again";
    B = C + B;
    B.Show();
    cout << "B.Find('g') ==> " << B.Find('g') << endl;

    //Проверка DecStr
    DecStr* obj4 = dynamic_cast <DecStr*>(pStr[4]);
    DecStr* obj5 = dynamic_cast <DecStr*>(pStr[5]);
    obj4->Show();
    obj5->Show();
    *(obj4) = *(obj4) + *(obj5);
    obj4->Show();
    *(obj5) = *(obj5) + 101;
    obj5->Show();
    DecStr D("5050");
    D.Show();
    *(obj5) = *(obj5)-D;
    obj5->Show();
    cout << "(D > *(obj4)) ==> " << (D > * (obj4)) << endl;
    cout << "(D > *(obj5)) ==> " << (D > * (obj5)) << endl;
    *(obj5) = D;
    obj5->Show();

    delete[] pStr; //очистка массива указателей pStr
    cout << "Для Stroka вызвано конструкторов копирования: " << Stroka::counter << endl;
    cout << "Для IdentStr вызвано конструкторов копирования: " << IdentStr::counter << endl; 
    cout << "Для DecStr вызвано конструкторов копирования: " << DecStr::counter << endl;
    return 0;
}
