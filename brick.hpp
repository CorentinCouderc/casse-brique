#pragma once

#ifndef BRICK_HPP
#define BRICK_HPP

#include <iostream>
#include "vec2.hpp"

/** A structure containing parameter of a brick */
struct brick
{
    /** x coordinate */
    float x_position;
    /** y coordinate */
    float y_position;
    /** width */
    float width;
    /** height */
    float height;

    /** Constructor brick(0,0) */
    brick();
    /** Constructor brick(x,y,w,h) */
    brick(float pos_x, float pos_y, float width, float height);

};


#endif
