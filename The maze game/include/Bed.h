#ifndef BED_H
#define BED_H
#include "Fixedobject.h"
#include <iostream>
using namespace std;
class Bed :public Fixedobject
{
    public:
        Bed(string nm , Room *currentR , string t="Fixed object"):Fixedobject(nm,currentR,t){};
        bool act();
};

#endif // BED_H
