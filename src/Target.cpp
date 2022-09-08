#include "Target.h"
#include "Point_float.h"
#include "Angle.h"

#include <cmath>



Target::Target()
{
    //ctor
}

Target::Target(LevelMap *mymap)
{
    level = mymap;
    player = reinterpret_cast<Entity*>(level->player_ptr);
    direct_angle = 0;
    //ctor
}

bool Target::visible(float abs_x, float abs_y)
{
    return level->levelwalls.visible(abs_x, abs_y, level->player_pos_x, level->player_pos_y);
}

bool Target::direct_path_available (float abs_x, float abs_y, float radius)
{

    constexpr float right = Angle::pi/2;
    constexpr float left = -Angle::pi/2;

    //set start point of the line between the player and enemy
    Point_float start_p;
    start_p.x = abs_x;
    start_p.y = abs_y;

    //set end point of the line between the player and enemy
    Point_float end_p;
    end_p.x = level->player_pos_x;
    end_p.y = level->player_pos_y;

    //create vector between the player and enemy
    direct_line = LineVec(start_p, end_p);

    direct_angle = direct_line.angle;

    //create vector to point the beginning of the visibility line
    LineVec left_aux_vec(start_p, radius, direct_line.angle + left);
    LineVec right_aux_vec(start_p, radius, direct_line.angle + right);

    if (side_visible(left_aux_vec))
    {
        return side_visible(right_aux_vec);
    }
    return 0;

}

float Target::distance(float abs_x, float abs_y)
{
    float deltaX = abs_x - level->player_pos_x;
    float deltaY = abs_y - level->player_pos_y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

bool Target::side_visible (const LineVec &aux_vec)
{

    //set start point of the side visibility line between the player and enemy
    Point_float visibility_line_start;
    visibility_line_start.x = aux_vec.x_end;
    visibility_line_start.y = aux_vec.y_end;

    //creating right visibility vector
    LineVec visibility_vec(visibility_line_start, direct_line.len, direct_line.angle);

    return level->levelwalls.visible(visibility_vec.x_start, visibility_vec.y_start, visibility_vec.x_end, visibility_vec.y_end);
}
