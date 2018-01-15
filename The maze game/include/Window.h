#ifndef WINDOW_H
#define WINDOW_H
#include "Fixedobject.h"
#include <iostream>
using namespace std;
class Window : public Fixedobject
{
    public:
        Window(string nm , Room *currentR , string t="Fixed object"):Fixedobject(nm,currentR,t){};
        bool act();



};

#endif // WINDOW_H
