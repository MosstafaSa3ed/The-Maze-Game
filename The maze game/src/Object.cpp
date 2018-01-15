#include "Object.h"
#include<iostream>
#include"Room.h"
using namespace std;

Object::Object()
{
    type="";
    name="";
    currentRoom=NULL;
}
Object ::Object(string nm, Room *currentR,string t="")
{
    type=t;
    name=nm;
    currentRoom=currentR;
    currentRoom->set_objects(this);
}

string Object::getname()
{
    return name;
}
string Object::gettype()
{
    return type;
}
