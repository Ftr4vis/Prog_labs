#pragma once
#ifndef __STROKA__
#define __STROKA__

class Stroka {
protected:
    int len;
    char* pCh;
public:
    static int counter;
    Stroka(int = 0);
    Stroka(char);
    Stroka(const char*);
    Stroka(const Stroka&);
    virtual ~Stroka();
    int GetLen(void) const {
        return len;
    }
    char* GetStr(void) const {
        return pCh;
    }
    void Clean() {
        if (pCh) delete[]pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        cout << "Очистка строки" << endl;
        return;
    }
    void Show(void) {
        cout << "pCh=" << pCh << endl;
        cout << "len=" << len << endl;
    }
};
#endif