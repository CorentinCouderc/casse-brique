#pragma once

#ifndef BRICK_HPP
#define BRICK_HPP

#include <iostream>
#include <vector>
#include "vec2.hpp"
#include "bonus.hpp"


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
    /** bonus */
    Bonus bonus;


    /** Constructor brick({0,0},0,0) */
    brick();
    /** Constructor brick({x,y},w,h) */
    brick(vec2 const& position, int const width, int const height,Bonus const bonus);

};

/** Construct a vector of bricks from the first brick*/
std::vector<brick> setBrickWall(brick first_brick);
/** Check if the brick is in contact with the ball */
bool detect_contact();
/** Decrease the breaking_number of the brick if hit by the ball */
int decrement_breaking_number();
/** Check if the brick is broken */
bool is_brick_broken();




#endif