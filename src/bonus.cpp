#include "bonus.hpp"


void selectBonus(paddle *pad,float* alpha, Bonus bonus)
{
    if (bonus==fasterBall||bonus==slowerBall)
        applyBonus(alpha,bonus);
    else
        applyBonus(pad,bonus);
}

void applyBonus(float* alpha, Bonus bonus)
{
    if(bonus==fasterBall && *alpha==1.0f)
    {
      *alpha = 1.5f;
    }

    if(bonus==slowerBall && *alpha==1.0f)
    {
        *alpha = 0.5f;
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
