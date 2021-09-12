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
#include <unistd.h>

extern Rgba BACKGROUND_COLOR;

namespace game
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

int SCREEN_HEIGHT = 950;
int SCREEN_WIDTH = 912;

class Game : public Framework {
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
        currentMode = Mode::MENU;
        menuCursor = MenuCursor::LVL_1;

        isKeyHeld[FRKey::UP] = false;
        isKeyHeld[FRKey::DOWN] = false;
        isKeyHeld[FRKey::LEFT] = false;
        isKeyHeld[FRKey::RIGHT] = false;

        player = Player(2*UNIT_SIZE,20*UNIT_SIZE);

        width = SCREEN_WIDTH;
        height = SCREEN_HEIGHT;
		fullscreen = false;
	}

	virtual bool Init() {

        sprites = LoadSprites();
		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {

        if(currentMode == Mode::MENU)
            drawMenu_();
        else if(currentMode == Mode::GAME)
        {
            static const int FRAME_DELAY = 100000/2;
            static int endPrevFrame = 0;

            if(FRAME_DELAY > (getTickCount() - endPrevFrame))
                usleep(FRAME_DELAY - getTickCount() + endPrevFrame);

            drawGame_();
            
            for(auto it = isKeyHeld.begin(); it != isKeyHeld.end(); ++it)
                if(it->second == true)
                {
                    player.run(it->first, lvl);
                    break;
                }

            drawPlayer_();

            endPrevFrame = getTickCount();
        }
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
            isKeyHeld[k] = true;
            switch(k)
            {
                case FRKey::LEFT:
                    player.setViewDir(Dir::LEFT);
                    break;
                case FRKey::RIGHT:
                    player.setViewDir(Dir::RIGHT);
                    break;
            }
        }
	}

    
	virtual void onKeyReleased(FRKey k)
    {
        if(currentMode == Mode::GAME)
        {
            isKeyHeld[k] = false;
            player.setMovementProgress(Movement::STAY);
        }
    }

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

    std::map<FRKey, bool> isKeyHeld;

    void drawMenu_();
    void drawGame_();
    void drawPlayer_();
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
        drawSprite(sprites[item], SCREEN_WIDTH/2 - sprite_w/2, i * SCREEN_HEIGHT/5+10);
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

void Game::drawPlayer_() 
{
    Sprite* s = sprites[SpriteName::player_view_right];

    bool isVerticalMove = (isKeyHeld[FRKey::UP] || isKeyHeld[FRKey::DOWN]) 
        && lvl.isLadderAbove(player.getX(), player.getY());


    bool isHorizontalMove = (isKeyHeld[FRKey::LEFT] || isKeyHeld[FRKey::RIGHT])
        && !lvl.isBlocker(FRKey::LEFT, player.getX(), player.getY())
        && !lvl.isBlocker(FRKey::RIGHT, player.getX(), player.getY());

    switch(player.getMovementProgress())
    {
        case Movement::MOVE_1:
        case Movement::MOVE_3:
            if(isHorizontalMove)
                s = (player.getViewDir() == Dir::LEFT) ? sprites[SpriteName::player_run0_l]
                    : sprites[SpriteName::player_run0_r];
            else if(isVerticalMove)
                s = sprites[SpriteName::grab1];
            break;

        case Movement::MOVE_2:
            if(isHorizontalMove)
            s = (player.getViewDir() == Dir::LEFT) ? sprites[SpriteName::player_run1_l]
                : sprites[SpriteName::player_run1_r];
            else if(isVerticalMove)
                s = sprites[SpriteName::grab2];
            break;

        case Movement::MOVE_4:
            if(isHorizontalMove)
            s = (player.getViewDir() == Dir::LEFT) ? sprites[SpriteName::player_run2_l]
                : sprites[SpriteName::player_run2_r];
            else if(isVerticalMove)
                s = sprites[SpriteName::grab3];
            break;
    }
    drawSprite(s, player.getX(), player.getY());

}

} 

int main(int argc, char *argv[])
{
    return run(new game::Game); 
}
