#pragma once

#ifndef BRICK_HPP
#define BRICK_HPP

#include <iostream>
#include "vec2.hpp"

/** A structure containing parameter of a brick */
struct brick
{
    /** coordinates */
    vec2 position;
    /** width */
    int width;
    /** height */
    int height;
    /** toughness */
    int breaking_number;
    /** state */
    bool is_broken;

    /** Constructor brick({0,0},0,0) */
    brick();
    /** Constructor brick({x,y},w,h) */
    brick(vec2 const& position, int const width, int const height);

};

/** Check if the brick is in contact with the ball */
bool detect_contact();
/** Decrease the breaking_number of the brick if hit by the ball */
int decrement_breaking_number();
/** Check if the brick is broken */
bool is_brick_broken();

#endif
