#include "paddle.hpp"


paddle::paddle()
    :position(),width(0),height(0)
{}

paddle::paddle(vec2 position_pad,int width_pad,int height_pad)
    :position(position_pad),
     width(width_pad),
     height(height_pad)
{}

/** Getter for width member variable
 * @return returns value of height
 */
int paddle::get_width()
{
    return width;
}

/** Getter for height member variable
 * @return returns value of height
 */
int paddle::get_height()
{
    return height;
}

/** Setter for width member variable
 */
void paddle::set_width(int new_width)
{
    width = new_width;
}

/** Setter for height member variable
 * @param new_height new height value to set height to
 */
void paddle::set_height(int new_height)
{
    height = new_height;
}
