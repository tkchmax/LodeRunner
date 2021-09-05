#include "Level.h"

namespace Game 
{
extern std::map<SpriteName, Sprite*> sprites;

void Level::createLevel() 
{
    unsigned cur = 0, y = 0;
    std::string amount;
    UNIT_TYPE type;
    while (rawLevel_[cur] != '.')
    {
        bool isUnitType = true;
        switch (rawLevel_[cur])
        {
        case 'r':
            type = UNIT_TYPE::Rock;
            break;
        case 'e':
            type = UNIT_TYPE::Empty;
            break;
        case 'l':
            type = UNIT_TYPE::Ladder;
            break;
        case 'b':
            type = UNIT_TYPE::BedRock;
            break;
        case 'g':
            type = UNIT_TYPE::Gold;
            break;
        case '/':
            y++;
            board_.push_back(std::vector<UNIT_TYPE>());
            break;
        default:
            amount += rawLevel_[cur];
            isUnitType = false;
            break;
        }
        if (isUnitType && !amount.empty())
        {
            for (unsigned x = 0; x < stoi(amount); ++x)
                board_.back().push_back(type);
            amount.clear();
        }
        cur++;
     }

    }


void Level::showBoard() 
{
    std::cout<<"h:"<<board_.size()<<"\tw: "<<board_[0].size()<<std::endl;
    for(int i=0; i<board_.size(); ++i)
    {
        for(int j = 0; j<board_[0].size(); ++j)
        {
            std::cout<<static_cast<int>(board_[i][j])<<" ";
        }
        std::cout<<std::endl;
    }
}


void Level::draw()
{
    const unsigned board_width = board_[0].size();
    for(unsigned i=1; i<board_.size(); ++i)
        assert(board_width == board_[i].size());
    assert(board_.size() != 0);
    
    unsigned x=0, y=0;
    SpriteName spriteToDraw;
    for(unsigned i=0; i<board_.size(); ++i)
    {
        for(unsigned j=0; j<board_[0].size(); ++j)
        {
            if(board_[i][j] != UNIT_TYPE::Empty)
            {    SpriteName name = static_cast<SpriteName>(board_[i][j]);
                 drawSprite(sprites[name], x, y);
            }
            x+=UNIT_SIZE;
        }
        y+=UNIT_SIZE;
        x=0;
    }

    drawSprite(sprites[SpriteName::player_widestep_right], UNIT_SIZE, y-2*UNIT_SIZE);
    
    /*draw game bar*/
    for(unsigned i=0; i<board_[0].size();++i)
    {
        drawSprite(sprites[SpriteName::separator_line], i*UNIT_SIZE, y);
        if(i<5)
        drawSprite(sprites[SpriteName::heart], i *UNIT_SIZE, y+UNIT_SIZE);
    }
    
    drawSprite(sprites[SpriteName::lvl1_short], 400, 23*UNIT_SIZE);
    
}

}
