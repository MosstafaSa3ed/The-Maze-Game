#include "Agent.h"
#include<iostream>
#include <set>
using namespace std;
Agent::Agent(){}
Agent::Agent(string name,Room* start_room,string type="")
{
    this->type=type;
    this->name=name;
    cur_room=start_room;
}

string Agent::getname()
{
    return name;
}
string Agent::gettype()
{
    return type;
}
void Agent::Pick_Object(Prop* p)
{
    my_objects.insert(p);
}
Room *Agent::getrom()
{
    return cur_room;
}
