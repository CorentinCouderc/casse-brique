#pragma once

#ifndef BONUS_HPP
#define BONUS_HPP

#include "paddle.hpp"
#include "vec2.hpp"


enum Bonus { none, largerPad, shorterPad, slowerBall, fasterBall };

/*select the object affected by the bonus*/
void selectBonus(paddle *pad,float *alpha, Bonus bonus);

/* apply the bonus to the pad*/
void applyBonus(paddle *pad,Bonus bonus);

/* apply the bonus to the ball*/
void applyBonus(float *alpha,Bonus bonus);


#endif // BONUS_H
