#include "Framework.h"
#include "Player.h"
#include "Guard.h"
#include "Level.h"
#include "SpritesLoad.h"

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

extern Rgba BACKGROUND_COLOR;

namespace Game
{

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

MenuCursor& operator--(MenuCursor& cursor, int)
{
    switch(cursor)
    {
        case MenuCursor::LVL_1: return cursor = MenuCursor::LVL_2;
        case MenuCursor::LVL_2: return cursor = MenuCursor::LVL_3;
        case MenuCursor::LVL_3: return cursor = MenuCursor::EXIT;
    }
    return cursor;
}

MenuCursor& operator++(MenuCursor& cursor, int)
{
    switch(cursor)
    {
        case MenuCursor::EXIT: return cursor = MenuCursor::LVL_3;
        case MenuCursor::LVL_3: return cursor = MenuCursor::LVL_2;
        case MenuCursor::LVL_2: return cursor = MenuCursor::LVL_1;                               
    }
    return cursor;
}


std::map<SpriteName, Sprite*> sprites;

int HEIGHT = 950;
int WIDTH = 912;

class Game : public Framework {
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
        currentMode = Mode::MENU;
        menuCursor = MenuCursor::LVL_1;

        width = WIDTH;
        height = HEIGHT;
		fullscreen = false;
	}

	virtual bool Init() {

        sprites = LoadSprites();
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {

        (currentMode == Mode::MENU) ? drawMenu_() : drawGame_();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) 
    {
        if(currentMode == Mode::MENU)
        {
           switch(menuCursor)
           {
               case MenuCursor::LVL_1:
                   lvl = Level_1();
                   break;
           } 
           currentMode = Mode::GAME;
        }
	}
    

	virtual void onKeyPressed(FRKey k) 
    {
        if(currentMode == Mode::MENU)
        {
            switch(k)
            {
                case FRKey::UP:
                    menuCursor++; 
                    break;
                case FRKey::DOWN:
                    menuCursor--;
                    break;

            }
        }
        else if(currentMode == Mode::GAME)
        {
        }
	}

    
	virtual void onKeyReleased(FRKey k) { }

	virtual const char* GetTitle() override
	{
		return "Lode Runner";
	}

private:
    Player player;
    std::vector<Guard> guards;
    Level lvl;

    Mode currentMode;
    MenuCursor menuCursor;

    void drawMenu_();
    void drawGame_();
};

void Game::drawMenu_()
   
{
    assert(currentMode == Mode::MENU);
    
    BACKGROUND_COLOR.r = 0xA0;
    BACKGROUND_COLOR.g = 0xA0;
    BACKGROUND_COLOR.b = 0xA0;
    BACKGROUND_COLOR.a = 0xFF;

    int sprite_w, sprite_h;
    std::vector<SpriteName> spritesToDraw = {SpriteName::Logo,
        SpriteName::lvl1_red_icon, SpriteName::lvl2_red_icon, SpriteName::lvl3_red_icon};
    
    //Change icon color under cursor
    SpriteName old_sprite, new_sprite;
    switch(menuCursor)
    {
        case MenuCursor::LVL_1:
            old_sprite = SpriteName::lvl1_red_icon;
            new_sprite = SpriteName::lvl1_green_icon;
            break;
        case MenuCursor::LVL_2:
            old_sprite = SpriteName::lvl2_red_icon;
            new_sprite = SpriteName::lvl2_green_icon;
            break;
        case MenuCursor::LVL_3:
            old_sprite = SpriteName::lvl3_red_icon;
            new_sprite = SpriteName::lvl3_green_icon;
            break;
    }
    std::replace(spritesToDraw.begin(), spritesToDraw.end(), old_sprite, new_sprite);
    
    int i=0;
    for(auto item : spritesToDraw)
    {
        getSpriteSize(sprites[item], sprite_w, sprite_h);
        drawSprite(sprites[item], WIDTH/2 - sprite_w/2, i * HEIGHT/5+10);
        i++;
    }

}

void Game::drawGame_()
{
    BACKGROUND_COLOR.r = 0x0;
    BACKGROUND_COLOR.g = 0x0;
    BACKGROUND_COLOR.b = 0x0;
    BACKGROUND_COLOR.a = 0x0;


    lvl.draw();
}

} 

int main(int argc, char *argv[])
{
    return run(new Game::Game); 
}
