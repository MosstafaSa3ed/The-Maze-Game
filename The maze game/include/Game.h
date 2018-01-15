#ifndef GAME_H
#define GAME_H
#include "Room.h"
#include "Agent.h"
#include "Player.h"
class Game
{
    public:
        Game();
        void play();
    protected:
        int cnt;
        Room *cur_room;
        vector<Room*>s;


};

#endif // GAME_H
