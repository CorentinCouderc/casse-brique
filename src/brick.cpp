
#include "brick.hpp"


brick::brick()
    :position(),width(0),height(0),breaking_number(1),is_broken(false),bonus(none)
{}

brick::brick(vec2 const& position_param,int const width_param,int const height_param,Bonus bonus_param)
    :position(position_param),
     width(width_param),
     height(height_param),
     breaking_number(1),
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

    for (int i=0;i<4;i++)
    {
        for (int j=0;j<720/w;j++)
        {
            brick add_brick = brick({pos_x+j*w,pos_y+i*h},w,h,none);
            brick_wall.push_back(add_brick);
        }
    }

    return brick_wall;
}


bool detect_contact()
{
    return true;
}

int decrement_breaking_number()
{
    return 0;
}

bool is_brick_broken()
{
    return true;
}
