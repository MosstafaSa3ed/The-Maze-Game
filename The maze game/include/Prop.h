#ifndef PROP_H
#define PROP_H
#include "Object.h"
//#include<iostream>
//using namespace std;
class Prop : public Object
{
    public:
        Prop( string nm , Room *currentR , string t="Prop"):Object (nm,currentR,t){};
        bool act();
};

#endif // PROP_H
