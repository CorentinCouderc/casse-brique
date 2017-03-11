#include "bonus.hpp"

void selectBonus(paddle *pad,vec2 *speed, Bonus bonus)
{
    if (bonus==fasterBall||bonus==slowerBall)
        applyBonus(speed,bonus);
    else
        applyBonus(pad,bonus);
}

void applyBonus(vec2 *speed, Bonus bonus)
{
    if(bonus==fasterBall)
    {
        speed->y*=2;
    }

    if(bonus==slowerBall)
    {
        speed->y/=2;
    }
}

void applyBonus(paddle *pad, Bonus bonus)
{
    if(bonus==largerPad)
    {
        pad->width*=2;
    }

    if(bonus==shorterPad)
    {
        pad->width/=2;
    }
}
