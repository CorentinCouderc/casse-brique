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

    /** Getter for width member variable
     * @return returns value of height
     */
    int get_width();

    /** Getter for height member variable
     * @return returns value of height
     */
    int get_height();

    /** Setter for width member variable
     */
    void set_width(int new_width);

    /** Setter for height member variable
     * @param new_height new height value to set height to
     */
    void set_height(int new_height);

};



#endif // PADDLE_HPP

