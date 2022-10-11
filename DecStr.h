#pragma once
#ifndef __DECSTR__
#define __DECSTR__
#include "Stroka.h"

class DecStr : public Stroka {
public:
    DecStr(int = 0); 
    DecStr(const char*);
    DecStr(const DecStr&);
    virtual ~DecStr();
    static int counter;
    DecStr& operator = (const DecStr&);
    friend DecStr operator + (const DecStr&, const DecStr&);
    friend DecStr operator + (const DecStr&, int);
    friend DecStr operator - (const DecStr&, const DecStr&);
    friend int operator > (const DecStr&, const DecStr&);
};
#endif