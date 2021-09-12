#pragma once
#ifndef SPRITESLOAD_H
#define SPRITESLOAD_H

#include <map>
#include "Framework.h"
enum class SpriteName
{
    Rock,
    BedRock,
    Ladder,
    Gold,
    Logo,
    lvl1_red_icon,
    lvl2_red_icon,
    lvl3_red_icon,
    lvl1_green_icon,
    lvl2_green_icon,
    lvl3_green_icon,
    lvl1_blue_h38,
    lvl2_blue_h38,
    lvl1_short,
    separator_line,
    heart,
    
    player_view_right,
    player_run0_l,
    player_run1_l,
    player_run2_l,
    player_run0_r,
    player_run1_r,
    player_run2_r,
    
    grab1,
    grab2,
    grab3,

    player_widestep_right

};

class Sprite;

std::map<SpriteName, Sprite*> LoadSprites();

#endif
