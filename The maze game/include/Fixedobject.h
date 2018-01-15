#ifndef FIXEDOBJECT_H
#define FIXEDOBJECT_H
#include <iostream>
#include "Room.h"
using namespace std;

class Fixedobject:public Object
{
    public:
        Fixedobject( string nm , Room *currentR , string t="Fixed object") : Object (nm,currentR,t){};
        virtual bool act()=0;
};

#endif // FIXEDOBJECT_H
