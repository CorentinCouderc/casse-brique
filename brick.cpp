
#include "brick.hpp"


brick::brick()
    :position(),width(0),height(0),breaking_number(1),is_broken(false)
{}

brick::brick(vec2 const& position_param,int const width_param,int const height_param)
    :position(position_param),
     width(width_param),
     height(height_param),
     breaking_number(1),
     is_broken(false)
{}




bool detect_contact()
{
    return true;
}

int decrement_breaking_number()
{
    return 0;
}

bool is_brick_broken()
{
    return true;
}
