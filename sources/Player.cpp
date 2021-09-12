#include "Player.h"
#include <functional>

extern int UNIT_SIZE;

namespace game 
{

    void Player::run(FRKey k, const Level& lvl)
    {
        switch(k)
        {
            case FRKey::LEFT:
                if(!lvl.isBlocker(FRKey::LEFT, x, y))
                {
                    shiftY_();
                    x -= UNIT_SIZE/4;
                }
                break;
            case FRKey::RIGHT:
                if(!lvl.isBlocker(FRKey::RIGHT, x, y))
                {
                    shiftY_();
                    x += UNIT_SIZE/4;
                }
                break;
            case FRKey::UP:
                if(!lvl.isBlocker(FRKey::UP, x,y) && lvl.isLadderAbove(x,y))
                {
                    shiftX_();
                    y -= UNIT_SIZE/4;
                }
                break;
            case FRKey::DOWN:
                if(!lvl.isBlocker(FRKey::DOWN, x, y) && lvl.isLadderUnder(x,y))
                {
                    shiftX_();
                    y += UNIT_SIZE/4;
                }
                break;
        }
        movementProgress++;
    }

}
