
#include "bonus.hpp"
#include "brick.hpp"
#include <cstdlib>
#include <ctime>


brick::brick()
    :position(),width(0),height(0),is_broken(false),bonus(none)
{}

brick::brick(vec2 const& position_param,int const width_param,int const height_param,Bonus bonus_param)
    :position(position_param),
     width(width_param),
     height(height_param),
     is_broken(false),
     bonus(bonus_param)

{}


std::list<brick> setBrickWall(brick first_brick)
{
    std::list<brick> brick_wall;
    float const pos_x=first_brick.position.x;
    float const pos_y=first_brick.position.y;
    int const w=first_brick.width;
    int const h=first_brick.height;
    Bonus aleat_bonus;
    srand(time(NULL));
    int aleat_number=0;

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<720/w;j++)
        {
            aleat_number = rand()%20;
            aleat_bonus = aleatBonus(aleat_number);
            brick add_brick = brick({pos_x+j*w,pos_y+i*h},w,h,aleat_bonus);
            brick_wall.push_back(add_brick);
        }
    }

    return brick_wall;
}

Bonus aleatBonus (int aleat_number)
{
    Bonus bonus;

    if (aleat_number <= 15)
    {
        bonus = none;
        return bonus;
    }
    else
    {
        switch(aleat_number)
        {
            case 16:
                bonus = largerPad;
                return bonus;
            case 17:
                bonus = shorterPad;
                return bonus;
            case 18:
                bonus = fasterBall;
                return bonus;
            case 19:
                bonus = slowerBall;
                return bonus;
            default:
                puts("Error in setAleatBonus(): case not corresponding");
                break;
        }
    }
    puts("Je retourne none");
    return none;
}
