#ifndef PLAYER_H
#define PLAYER_H
#include"Monster.h"
#include "Agent.h"
class Player:public Agent
{
public:
    static bool done;
    Player(string name,Room *start,string type="Player"):Agent(name,start,type) {};
    bool act();
    void Drop_Object(Prop*);
    void printMyObject();
    Monster *x;
private:
    int limit=0;
};

#endif // PLAYER_H
