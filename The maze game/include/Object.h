#ifndef OBJECT_H
#define OBJECT_H
#include<iostream>
#include <set>
using namespace std;
class Room;

class Object
{
public:
    Object();
    Object( string nm , Room* currentR ,string t );
    virtual bool act()=0;
    string getname();
    string gettype();

protected:
    string name;
    Room *currentRoom;
    string type;
};

#endif // OBJECT_H
