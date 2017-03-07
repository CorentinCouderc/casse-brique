#pragma once

#ifndef PADDLE_HPP
#define PADDLE_HPP


#include <iostream>
#include "vec2.hpp"

/** A structure containing parameter of the paddle */
struct paddle
{
    /** coordinates */
    vec2 position;
    /** width */
    int width;
    /** height */
    int height;
    /** state */


    /** Constructor paddle({0,0},0,0) */
    paddle();
    /** Constructor paddle({x,y},w,h) */
    paddle(vec2 position, int width, int height);

};

#endif // PADDLE_HPP

