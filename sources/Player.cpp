#include "Player.h"

extern int UNIT_SIZE;

namespace game 
{

void Player::run(FRKey k, const Level& lvl)
{
  switch(k)
  {
      case FRKey::LEFT:
        x -= UNIT_SIZE/4;

        break;
      case FRKey::RIGHT:
        x += UNIT_SIZE/4;
  }
}

}
