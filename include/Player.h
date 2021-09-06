#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

namespace game 
{
    
class Player : public Character 
{
public:
    Player() : Character() {}
    Player(int start_x, int start_y) : Character(start_x, start_y) {}
    void run(FRKey k, const Level& lvl);
private:
};

}
#endif
