#ifndef OTHERS_H
#define OTHERS_H
#include "Fixedobject.h"
#include <iostream>
using namespace std;

class Others  :public Fixedobject
{
    public:
        Others(string nm , Room *currentR , string t="Fixed object"):Fixedobject(nm,currentR,t){};
        bool act();
};




#endif // OTHERS_H
