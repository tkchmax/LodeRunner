#include "Character.h"

namespace game {
Movement& operator++(Movement& m, int)
{
    switch(m)
    {
        case Movement::STAY: return m = Movement::MOVE_1;
        case Movement::MOVE_1: return m = Movement::MOVE_2;
        case Movement::MOVE_2: return m = Movement::MOVE_3;
        case Movement::MOVE_3: return m = Movement::MOVE_4;
        case Movement::MOVE_4: return m = Movement::MOVE_1;
    }
    return m;
}

void Character::shiftX_()
{
    unsigned xTemp = (x+UNIT_SIZE/2)/UNIT_SIZE;
    unsigned yTemp = (y+UNIT_SIZE/2)/UNIT_SIZE;
    x = xTemp*UNIT_SIZE;
    //y = yTemp*UNIT_SIZE;
}
void Character::shiftY_()
{
    unsigned yTemp = (y+UNIT_SIZE/2)/UNIT_SIZE;
    y = yTemp * UNIT_SIZE;
}

bool Character::isFalling(const Level& lvl) 
{
    unsigned xUnder = (x+UNIT_SIZE/2)/UNIT_SIZE;
    unsigned yUnder = (y+UNIT_SIZE)/UNIT_SIZE;
    return lvl.getBoard()[yUnder][xUnder] == UNIT_TYPE::Empty;
}

}
