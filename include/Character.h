#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Framework.h"
#include "Level.h"
#include <vector>
#include <map> 
#include <iostream>

namespace game
{

enum class Movement 
{
    STAY,
    SMALL_STEP,
    WIDE_STEP
};

enum class Dir
{
    LEFT,
    RIGHT
};

class Character 
{
    public:
        Character() : x(0), y(0), currentMovement(Movement::STAY), viewDir(Dir::LEFT) {}
        Character(unsigned start_x, unsigned start_y) : x(start_x), y(start_y) {}
        unsigned getX() {return x;}
        unsigned getY() {return y;}
        bool isFalling();
    protected:
        unsigned x,y;
        Dir viewDir;
        Movement currentMovement;        
};


}
#endif
