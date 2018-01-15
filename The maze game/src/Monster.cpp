#include "Monster.h"
#include <stdlib.h>
#include "Room.h"
#include<string.h>


bool Monster ::act ()
{
    if(attitude=="1" && flag)
    {
        int n = rand() %  cur_room->directions.size();
        direction=cur_room->directions[n];
            cur_room->leave(this);
            cur_room = cur_room->getLinked(direction);
            cur_room->enter(this);
    }
    return flag;
}

void Monster::die()
{
    flag=0;
    cur_room->leave(this);
}


void Monster::edges()
{

adj[1].push_back(3);
adj[1].push_back(4);
adj[1].push_back(5);
adj[1].push_back(2);
adj[1].push_back(16);
adj[2].push_back(1);
adj[3].push_back(1);
adj[3].push_back(7);
adj[3].push_back(6);
adj[4].push_back(1);
adj[4].push_back(14);
adj[5].push_back(1);
adj[5].push_back(8);
adj[5].push_back(13);
adj[6].push_back(3);
adj[7].push_back(3);
adj[8].push_back(5);
adj[8].push_back(9);
adj[8].push_back(12);
adj[9].push_back(11);
adj[9].push_back(10);
adj[10].push_back(9);
adj[11].push_back(9);
adj[12].push_back(8);
adj[13].push_back(5);
adj[14].push_back(4);
adj[14].push_back(15);
adj[16].push_back(1);
}

int Monster::Dfs(int cur , int dis){

if(cur==dis)return 0;
if(vis[cur])return 1e9;
vis[cur]=true;
int ans=1e9;
for(int i=0 ; i<adj[cur].size() ; i++){
    ans=min(ans , 1+Dfs(adj[cur][i] , dis));
}
return ans;
}

void Monster::findtheway(vector<Room*>& arr)
{

    int mn=10000,ind,x;
    edges();
    for(int i=0;i<arr.size();i++)
    {

        for(int j=0;j<cur_room->directions.size();j++)
        {
            string str=cur_room->directions[j];
            Room*r=(cur_room->getLinked(str));
            memset(vis,0,sizeof vis);
            x=Dfs(r->rom[r],arr[i]->rom[arr[i]]);
            if(x<mn){
                mn=x;
                ind=j;
            }
        }

    }
    if(flag){
    cur_room->leave(this);
    cur_room=cur_room->getLinked(cur_room->directions[ind]);
    cur_room->enter(this);
    }
}
