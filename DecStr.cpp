#include <iostream>
#include "Stroka.h"
#include "DecStr.h"

using namespace std;
extern "C" int __stdcall summa(int, int);
extern "C" char* __stdcall itostr(int);

DecStr::DecStr(int val) : Stroka(val) {
    cout << "DecStr::DecStr(int val):Stroka(val)" << endl;
}
DecStr::~DecStr() {
    cout << "DecStr::~DecStr()" << endl;
}
DecStr::DecStr(const char* Str) : Stroka(Str) {
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[0] == '+') || pCh[0] != '0')) {
        cout << "Недопустимый символ, pCh[0] =" << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!(pCh[i] >= '0' && pCh[i] <= '9')) {
            cout << "Недопустимая строка, pCh[" << i << "] = " << pCh[i] << endl;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "DecStr::DecStr(const char* Str) : Stroka(Str)" << endl;
}
int DecStr::counter = 0;
DecStr::DecStr(const DecStr& from) : Stroka(from) {
    counter++;
    cout << "DecStr::DecStr(const DecStr& from) : Stroka(from)" << endl;
}
DecStr& DecStr :: operator = (const DecStr& DS) {
    if (&DS != this) {
        delete[] pCh;
        len = strlen(DS.pCh);
        pCh = new char[len + 1];
        strcpy_s(pCh, len + 1, DS.pCh);
    }
    cout << "DecStr& DecStr :: operator =(const DecStr& DS)" << endl;
    return *this;
}
DecStr operator + (const DecStr& pobj1, const DecStr& pobj2) {
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.GetStr());
    num2 = atoi(pobj2.GetStr());
    char* pTmpCh;
    int A = summa(num1, num2);
    if (tmp.len >= pobj2.len) {
        pTmpCh = new char[tmp.len + 2];
        _itoa_s(A, pTmpCh, tmp.len + 2, 10);
    }
    else {
        pTmpCh = new char[pobj2.len + 2];
        _itoa_s(A, pTmpCh, pobj2.len + 2, 10);
    }
    if (tmp.pCh) delete[] tmp.pCh;
    tmp.pCh = pTmpCh;
    tmp.len = strlen(tmp.pCh);
    cout << "DecStr operator +(const DecStr& pobj1, const DecStr& pobj2)" << endl;
    return tmp;
}
DecStr operator + (const DecStr& pobj1, int obj) {
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.GetStr());
    num2 = obj;
    char* pTmpCh;
    int A = summa(num1, num2);
    if (tmp.len >= strlen(itostr(obj))) {
        pTmpCh = new char[tmp.len + 2];
        _itoa_s(A, pTmpCh, tmp.len + 2, 10);
    }
    else {
        pTmpCh = new char[strlen(itostr(obj)) + 2];
        _itoa_s(A, pTmpCh, strlen(itostr(obj)) + 2, 10);
    }
    if (tmp.pCh) delete[] tmp.pCh;
    tmp.pCh = pTmpCh;
    tmp.len = strlen(tmp.pCh);
    cout << "DecStr operator +(const DecStr& pobj1, int obj)" << endl;
    return tmp;
}
DecStr operator - (const DecStr& pobj1, const DecStr& pobj2) {
    int num1, num2;
    DecStr tmp(pobj1);
    num1 = atoi(tmp.GetStr());
    num2 = atoi(pobj2.GetStr());
    char* pTmpCh;
    int A = num1 - num2;
    if (tmp.len >= pobj2.len) {
        pTmpCh = new char[tmp.len + 2];
        _itoa_s(A, pTmpCh, tmp.len + 2, 10);
    }
    else {
        pTmpCh = new char[pobj2.len + 2];
        _itoa_s(A, pTmpCh, pobj2.len + 2, 10);
    }
    if (tmp.pCh) delete[] tmp.pCh;
    tmp.pCh = pTmpCh;
    tmp.len = strlen(tmp.pCh);
    cout << "DecStr operator -(const DecStr& pobj1, const DecStr& pobj2)" << endl;
    return tmp;
}
int operator > (const DecStr& pobj2, const DecStr& pobj1) {
    int num1, num2;
    DecStr tmp(pobj1.pCh);
    num1 = atoi(tmp.GetStr());
    num2 = atoi(pobj2.GetStr());
    int A = (num1 > num2) ? 1 : 0;
    cout << "int operator >(const DecStr& pobj2)" << endl;
    return A;
}