#pragma once 

#ifndef LEVEL_H
#define LEVEL_H

#include "Framework.h"
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <map>
#include "SpritesLoad.h"

namespace game
{
   
const int UNIT_SIZE = 38; 

enum class UNIT_TYPE 
{
    Rock,
    BedRock,
    Ladder,
    Gold,
    Empty
};

class Level 
{
    public:
        Level() : rawLevel_("none"), nGuards_(0){}
        void draw();
        void showBoard();
        const std::vector<std::vector<UNIT_TYPE>>& getBoard() {return board_;}
    private:
        std::vector<std::vector<UNIT_TYPE>> board_;
        std::string rawLevel_;
        unsigned nGuards_;

        void createLevel();
    protected:
        Level(std::string rawLevel, unsigned nGuards) : rawLevel_(rawLevel), nGuards_(nGuards){createLevel();}
};


class Level_1 : public Level
{
    public:
        Level_1() : Level("/23e1r/23e1r/1r8r1l3r10e1r/1r8e1l13e1r/1r8e1l4e2r1l6e1r/1r8e1l4e2\
r1l4e1g1e1r/1r8e1l4e2r1l3e3r1r/1r8e1l4e2r1l6e1r/1r8e1l4e2r1l6e1r\
/1r8e1l4e2r1l6e1r/1r4r1l4r4e3r1l5r1r/1r4e1l11e1l5e1r/1r4e1l11e1l5e1r/1r3e1e1l8e1g2e1l5e1r/1r10r1l5b1l5e1r/1r10e1l5e1l5e1r/\
1r10e1l5e1l5e1r/1r9e1g1l5e1l2e1g2e1r/1r6e1l5r4e5r1l1r/1r6e1l14e1l1r/1r6e1l14e1l1r/24r.", 3) {}

};

}
#endif



