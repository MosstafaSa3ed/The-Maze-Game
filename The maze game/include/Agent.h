#ifndef AGENT_H
#define AGENT_H
#include<set>
#include "Prop.h"

class Room;
class Agent
{
public:

        Agent();
        Agent(string,Room*,string);
        virtual bool act()=0;
        string getname();
        string gettype();
        bool check(string);
        void Pick_Object(Prop*);
        Room *getrom();
    protected:
        set<Prop*> my_objects;
        Prop *prop;
        Room *cur_room;
        string name,type;
};

#endif // AGENT_H
