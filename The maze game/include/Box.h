#ifndef BOX_H
#define BOX_H
#include "Fixedobject.h"
#include <iostream>
using namespace std;
class Box : public Fixedobject
{
    public:
        Box (string nm , Room *currentR , string t="Fixed object"):Fixedobject(nm,currentR,t){};
        bool act();


};

#endif // BOX_H
