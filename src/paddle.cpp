#include "paddle.hpp"


paddle::paddle()
    :position(),width(0),height(0)
{}

paddle::paddle(vec2 position_pad,int width_pad,int height_pad)
    :position(position_pad),
     width(width_pad),
     height(height_pad)
{}
