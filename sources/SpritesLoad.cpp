#include "SpritesLoad.h"

std::map<SpriteName, Sprite*> LoadSprites()
{
    std::map<SpriteName,Sprite*> sprites;

    sprites[SpriteName::Logo] = createSprite("../data/menu/logo.png");
    sprites[SpriteName::lvl1_red_icon] = createSprite("../data/menu/lvl1_red.png");
    sprites[SpriteName::lvl2_red_icon] = createSprite("../data/menu/lvl2_red.png");
    sprites[SpriteName::lvl3_red_icon] = createSprite("../data/menu/lvl3_red.png");
    sprites[SpriteName::lvl1_green_icon] = createSprite("../data/menu/lvl1_green.png");
    sprites[SpriteName::lvl2_green_icon] = createSprite("../data/menu/lvl2_green.png");
    sprites[SpriteName::lvl3_green_icon] = createSprite("../data/menu/lvl3_green.png");
    sprites[SpriteName::Rock] = createSprite("../data/level/rock.png");
    sprites[SpriteName::BedRock] = createSprite("../data/level/bedrock.png");
    sprites[SpriteName::Ladder] = createSprite("../data/level/ladder.png");
    sprites[SpriteName::Gold] = createSprite("../data/level/gold2.png");
    sprites[SpriteName::separator_line] = createSprite("../data/level/blue_line.png");
    sprites[SpriteName::heart] = createSprite("../data/level/heart.png");
    sprites[SpriteName::player_widestep_right] = createSprite("../data/player_widestep_right.png");
    sprites[SpriteName::lvl1_blue_h38] = createSprite("../data/menu/lvl1_blue_h38.png");
    sprites[SpriteName::lvl2_blue_h38] = createSprite("../data/menu/lvl2_blue_h38.png");
    sprites[SpriteName::lvl1_short] = createSprite("../data/menu/lvl1_short.png");
    sprites[SpriteName::player_view_right] = createSprite("../data/characters/player_view_right.png");
    sprites[SpriteName::player_run0_l] = createSprite("../data/characters/run0_l.png");
    sprites[SpriteName::player_run1_l] = createSprite("../data/characters/run1_l.png");
    sprites[SpriteName::player_run2_l] = createSprite("../data/characters/run2_l.png");
    sprites[SpriteName::player_run0_r] = createSprite("../data/characters/run0_r.png");
    sprites[SpriteName::player_run1_r] = createSprite("../data/characters/run1_r.png");
    sprites[SpriteName::player_run2_r] = createSprite("../data/characters/run2_r.png");
    sprites[SpriteName::grab1] = createSprite("../data/characters/grab1.png");
    sprites[SpriteName::grab2] = createSprite("../data/characters/grab2.png");
    sprites[SpriteName::grab3] = createSprite("../data/characters/grab3.png");

    return sprites;
}

