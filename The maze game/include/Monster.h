#ifndef MONSTER_H
#define MONSTER_H
#include "Agent.h"
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
using namespace std;

class Monster:public Agent
{
public:
    Monster(string name,Room *start,string type="Monster"):Agent(name,start,type) {};
    bool act();
    void die();
    int play(Room*);
    string attitude;
    int Dfs(int cur , int dis);
    void findtheway(vector<Room*>&);
    void getdest(string s);
    void edges();
private:
    bool flag=1;
    vector<int> adj[17];
    bool vis[20];
    string des;
    string direction ;

};

#endif
