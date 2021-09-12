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
    MOVE_1,
    MOVE_2,
    MOVE_3,
    MOVE_4
};

Movement& operator++(Movement& m, int);

enum class Dir
{
    LEFT,
    RIGHT
};



class Character 
{
    public:
        Character() : x(0), y(0), movementProgress(Movement::STAY),  viewDir(Dir::LEFT) {}
        Character(unsigned start_x, unsigned start_y) : x(start_x), y(start_y) {}
        unsigned getX() {return x;}
        unsigned getY() {return y;}
        Movement getMovementProgress() {return movementProgress;}
        Dir getViewDir() {return viewDir;}
        Character& setViewDir(Dir d) {viewDir = d; return *this;}
        Character& setMovementProgress(Movement m) {movementProgress = m; return *this;} 
        bool isFalling();

    protected:
        unsigned x,y;
        Dir viewDir;
        //Movement currentMovement;        
        Movement  movementProgress;
};


}
#endif
