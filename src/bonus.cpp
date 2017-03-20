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
       if (speed->y >0) speed->y=60.0f;
       else speed->y=-60.0f;
    }

    if(bonus==slowerBall)
    {
        if (speed->y >0) speed->y=15.0f;
        else speed->y=-15.0f;
    }
}

void applyBonus(paddle *pad, Bonus bonus)
{
    if(bonus==largerPad)
    {
        pad->width=100*2;
    }

    if(bonus==shorterPad)
    {
        pad->width=100/2;
    }
}
