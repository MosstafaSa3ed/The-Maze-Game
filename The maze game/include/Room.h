#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include<iostream>
#include<set>
#include<map>
#include "Object.h"
#include "Agent.h"
#include "Monster.h"
using namespace std;
class Agent;
class Room
{
private:
    string name;
    string description;
    map<string,Room*> linking;
    vector<Object*> objects_fe_oda;
    vector<Agent*>va;
public:
    Room();
    Room( string, string,int);
    int node;
    map<Room*,int> rom;
    string getName();
    string getDescription();
    vector<string> directions;
    void set_objects(Object*);
    bool fe_elprop_da_yta5d(string);
    bool checklinked(string);
    void printoccupent();
    void link(Room*, string);
    Room *getLinked(string direction);
    void printLinked();
    int searchMonster();
    void enter(Agent*);
    void leave(Agent*);
    void Print_Objects();
    Monster *get_mon();
    Prop *get_prop(string);
};

#endif
