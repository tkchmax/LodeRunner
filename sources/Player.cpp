#include "Player.h"

extern int UNIT_SIZE;

namespace game 
{

void Player::run(FRKey k, const Level& lvl)
{
  switch(k)
  {
      case FRKey::LEFT:
          if(!lvl.isBlocker(FRKey::LEFT, x, y))
            x -= UNIT_SIZE/4;

        break;
      case FRKey::RIGHT:
        if(!lvl.isBlocker(FRKey::RIGHT, x, y))
            x += UNIT_SIZE/4;
        break;
  }
  movementProgress++;
}

}
