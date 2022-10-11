#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stroka.h"
#include "IdentStr.h"

using namespace std;

IdentStr::IdentStr(int val) : Stroka(val) {
    cout << "IdentStr::IdentStr(int val) : Stroka(val)" << endl;
}
IdentStr::IdentStr(char ch) : Stroka(ch) {
    if (!(('a' <= pCh[0] && pCh[0] <= 'z') || ('A' <= pCh[0] && pCh[0] <= 'Z'))) {
        cout << "Недопустимый символ, pCh[0]=" << pCh[0] << endl;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    cout << "IdentStr::IdentStr(char ch) : Stroka(ch)" << endl;
}
IdentStr::IdentStr(const char* Str) : Stroka(Str) {
    const char* keyword[] = { "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq" };
    int size = 84;
    for (int i = 0; i < size; i++) {
        if (strcmp(pCh, keyword[i]) == 0) {  
            cout << "Недопустимая строка, pCh=" << pCh << endl;
            if (pCh) delete[]pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    if (!(('a' <= pCh[0] && pCh[0] <= 'z') || ('A' <= pCh[0] && pCh[0] <= 'Z') || pCh[0] == '_')) {
        cout << "Недопустимый символ, pCh[0]=" << pCh[0] << endl;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!(('0' <= pCh[i] && pCh[i] <= '9') || ('a' <= pCh[i] && pCh[i] <= 'z') || ('A' <= pCh[i] && pCh[i] <= 'Z') || pCh[i] == '_')) {
            cout << "Недопустимый символ, pCh[" << i << "]=" << pCh[i] << endl;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char* Str) : Stroka(Str)" << endl;
}
int IdentStr::counter = 0;
IdentStr::IdentStr(const IdentStr& from) : Stroka(from) {
    counter++;
    cout << "IdentStr::IdentStr(const IdentStr& from) : Stroka(from)" << endl;
}
int IdentStr::Find(char ch) {
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (ch == pCh[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) cout << "Символ не входит в строку" << endl;
    return index;
}
IdentStr::~IdentStr() {
    cout << "IdentStr::~IdentStr()" << endl;
}
char& IdentStr:: operator [] (int index) {
    if (index >= 0 && index < len) {
        cout << "char& IdentStr:: operator [] (int index)" << endl;
        return pCh[index];
    }
    else return pCh[0];
}
IdentStr& IdentStr::operator = (const IdentStr& S) {
    if (&S != this) {
        len = strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy(pCh, S.pCh);
        cout << "IdentStr & IdentStr::operator = (const IdentStr & S)" << endl;
    }
    return *this;
}
IdentStr operator + (const IdentStr& pobj1, const IdentStr& pobj2) {
    IdentStr tmp(pobj1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    --i;
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[j++]);
    cout << "IdentStr operator+ (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;
    return tmp;
}
IdentStr operator + (const IdentStr& pobj1, const char* pobj2) {
    IdentStr tmp1(pobj2);
    IdentStr tmp(pobj1.GetLen() + tmp1.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = pobj1.pCh[j++]);
    --i;
    j = 0;
    while (tmp.pCh[i++] = tmp1.pCh[j++]);
    cout << "IdentStr operator + (const IdentStr& pobj1, const char* pobj2)" << endl;
    return tmp;
}
IdentStr operator + (const char* pobj1, const IdentStr& pobj2) {
    IdentStr tmp1(pobj1);
    IdentStr tmp(tmp1.GetLen() + pobj2.GetLen());
    int i = 0, j = 0;
    while (tmp.pCh[i++] = tmp1.pCh[j++]);
    --i;
    j = 0;
    while (tmp.pCh[i++] = pobj2.pCh[j++]);
    cout << "IdentStr operator + (const char* pobj1, const IdentStr& pobj2)" << endl;
    return tmp;
}
IdentStr IdentStr:: operator ~ () {
    char tmp;
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    }
    cout << "IdentStr IdentStr:: operator ~ ()" << endl;
    return *this;
}
int operator < (const IdentStr& pobj1, const IdentStr& pobj2) {
    int res = 0;
    int length;
    if (pobj1.len < pobj2.len) length = pobj1.len;
    else length = pobj2.len;
    for (int i = 0; i < length; i++) {
        int num1 = (int)pobj1.pCh[i];
        int num2 = (int)pobj2.pCh[i];
        if (num1 < num2) {
            res = 1;
            return res;
        }
    }
    cout << "operator < (const IdentStr& pobj1, const IdentStr& pobj2)" << endl;
    return pobj1.GetLen() < pobj2.GetLen();
}
