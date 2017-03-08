#include "paddle.hpp"


paddle::paddle()
    :position(),width(0),height(0)
{}

paddle::paddle(vec2 position_pad,int width_pad,int height_pad)
    :position(position_pad),
     width(width_pad),
     height(height_pad)
{}


int paddle::get_width()
{
    return width;
}

int paddle::get_height()
{
    return height;
}


void paddle::set_width(int new_width)
{
    width = new_width;
}


void paddle::set_height(int new_height)
{
    height = new_height;
}
