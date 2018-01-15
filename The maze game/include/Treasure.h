#ifndef TREASURE_H
#define TREASURE_H
#include "Object.h"
#include <iostream>
using namespace std;
class Treasure : public Object
{
    public:
    Treasure( string nm , Room *currentR , string t="Treasure" ) : Object (nm,currentR,t){};
    bool act();
};

#endif // TREASURE_H
