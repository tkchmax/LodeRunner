#pragma once
#ifndef GAME_H 
#define GAME_H


#include "Framework.h"
#include <cassert>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <type_traits>
#include <vector>
#include <algorithm>

#include "Guard.h"
#include "Player.h"
#include "Level.h"
#include "SpritesLoad.h"


class Guard;
class Player;

namespace game{

enum class Mode 
{
    MENU,
    GAME
};

enum class MenuCursor
{
    LVL_1,
    LVL_2,
    LVL_3,
    EXIT
};


class Game:public Framework{
    public:
        
        virtual void PreInit(int&,int&,bool&);
        virtual bool Init();
        virtual void Close();
        virtual bool Tick();
        virtual void onMouseMove(int,int,int,int);
        virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
        virtual void onKeyPressed(FRKey k);
        virtual void onKeyReleased(FRKey k);
        const char* GetTitle() override	{	return "Lode Runner";	}

    private:
    void foo(){std::cout<<"foo";}
    Player* player;
    std::vector<Guard*> guards;
    Level lvl;

    Mode currentMode;
    MenuCursor menuCursor;

    std::map<FRKey, bool> isKeyHeld;

    void drawMenu_();
    void drawGame_();
    friend class Player;
};

}
#endif
