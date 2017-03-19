#pragma once

#ifndef BRICK_HPP
#define BRICK_HPP

#include <iostream>
#include <list>
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
std::list<brick> setBrickWall(brick first_brick);
/** Return an aleat bonus from enum Bonus, with more weigh to 'none' */
Bonus aleatBonus(int aleat_number);


#endif
