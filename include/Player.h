#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Framework.h"

namespace Game 
{

class Player 
{
public:
    void draw();
    void move(FRKey k);
private:
    unsigned x, y;
    unsigned movementId;
};

}
#endif
