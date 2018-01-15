#include "Room.h"
#include "Agent.h"
#include <vector>
#include <set>
#include <iostream>
using namespace std;
Room::Room()
{
}

Room::Room( string name, string description,int x)
{
    node=x;
    this->name = name;
    this->description = description;
    //nodes[node]=this;
    rom[this]=node;
}

void Room::set_objects(Object* a)
{
    objects_fe_oda.push_back(a);
}
bool Room::fe_elprop_da_yta5d(string s)
{
    for(int i=0; i<objects_fe_oda.size(); i++)
    {
        if(s==objects_fe_oda[i]->getname() && objects_fe_oda[i]->act())
            return 1;
    }
    return 0;
}
Prop *Room::get_prop(string s)
{
    for(int i=0; i<objects_fe_oda.size(); i++)
    {
        if(s==objects_fe_oda[i]->getname())
            return dynamic_cast<Prop*>(objects_fe_oda[i]);
    }
}
void Room::link(Room *r, string direction)
{
    linking[direction] = r;
    directions.push_back(direction);
}
Room* Room::getLinked(string direction)
{
    return linking[direction];
}

bool Room::checklinked(string direction)
{
    for(int i=0; i<directions.size(); i++)
        if(directions[i]==direction)
            return 1;
    return 0;
}

void Room::printLinked()
{
    map<string, Room*> :: iterator i;
    cout<<"You can go to\n";
    for(i = linking.begin(); i != linking.end(); ++i)
    {
        cout <<" ... "<<i->first << endl;
    }
}



string Room::getName()
{
    return name;
}
void Room::printoccupent()
{
    if(va.size()==0)
        cout<<"There is nobody here !\n";
    else
    {
        cout<<"You can see ";
        for(int i=0; i<va.size(); i++)
            cout<<va[i]->getname()<<", ";
        cout<<"here\n";
    }
}
Monster *Room :: get_mon()
{

    for(int i=0 ; i<va.size(); i++)
    {
        if(va[i]->gettype()=="Monster")
            return dynamic_cast<Monster*>(va[i]);
    }
}

string Room::getDescription()
{
    return description;
}
///lesaaaaaaaaa
int Room::searchMonster()
{
    int x=0;
    for(int i=0 ; i<va.size(); i++)
    {
        if(va[i]->gettype()=="Monster")
            x++;
    }
    return x;
}
void Room::enter(Agent *a)
{
    va.push_back(a);
}
void Room::leave(Agent *a)
{
    for (int i = 0; i < va.size(); ++i)
    {
        if(va[i]==a)
        {
            va.erase(va.begin()+i);
            return;
        }
    }
}
void Room::Print_Objects()
{
    for(int i=0; i<objects_fe_oda.size(); i++)
    {
        if(objects_fe_oda[i]->getname()=="key")
            continue;
        cout<<objects_fe_oda[i]->getname()<<" .. ";
    }
    cout<<endl;
}
