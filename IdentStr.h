#pragma once
#ifndef __IDENTSTR__
#define __IDENTSTR__
#include "Stroka.h"
class IdentStr: public Stroka {
public:
    IdentStr(int = 0);
    IdentStr(char);
    IdentStr(const char*);
    IdentStr(const IdentStr&);
    virtual ~IdentStr();
    int Find(char);
    static int counter;
    char& operator [] (int);
    IdentStr& operator = (const IdentStr&);
    IdentStr operator ~ ();
    friend IdentStr operator + (const IdentStr&, const IdentStr&);
    friend IdentStr operator + (const IdentStr&, const char*);
    friend IdentStr operator + (const char*, const IdentStr&);
    friend int operator < (const IdentStr&, const IdentStr&);
};
#endif