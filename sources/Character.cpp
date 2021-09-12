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

}
