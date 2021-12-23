#include "Player.h"
#include "Scanner.h"

#include "Angle.h"
#include <cmath>

Player::Player()
{
    //ctor
    gun = nullptr;
}

Player::Player(LevelMap *mymap, Layers *lay, const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : MovObj::MovObj(filename, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    gun = new Weapons (1, mymap, lay);

    //set the sprite according to the gun used
    position = gun->act(position, angle);

    //set the speed in pixels per second
    speed = 200;

    //select sprite #0
    set_sprite(position);

}

void Player::go_move()
{
    if (Scanner::start_pressed)
    {
        terminated = 1;
        return;
    }


    Scanner::stick_nav = 1;
    //reset new position
    new_abs_y = abs_y;
    new_abs_x = abs_x;

    //get the distance to move
    move_delta = get_move_delta();


    if (Scanner::left_stick_moved)
    {
        new_abs_y = abs_y + move_delta*Scanner::lstick_y;
        new_abs_x = abs_x + move_delta*Scanner::lstick_x;
    }

    if (Scanner::right_stick_moved)
    {
        calc_stick_rad(Scanner::rstick_x, Scanner::rstick_y);
        angle = Angle::calcangle(sin_a, cos_a);

        /*asin(sin_a);
        if (cos_a < 0)
        {
            angle = pi - angle;
        }*/
    }

    else

    {
    if (Scanner::pad_multiple_pressed)
    {
        move_delta = move_delta/sqrt2;
    }

    //assign move directions
    if (Scanner::up_pressed)
    {
        new_abs_y = abs_y - move_delta;

    }
    if (Scanner::down_pressed)
    {
        new_abs_y = abs_y + move_delta;
    }
    if (Scanner::left_pressed)
    {
        new_abs_x = abs_x - move_delta;
    }
    if (Scanner::right_pressed)
    {
        new_abs_x = abs_x + move_delta;
    }

    }

    //if the new position is valid, assigning it as a current position
    if (level->valid_pos(new_abs_x, new_abs_y, radius))
    {
        abs_x = new_abs_x;
        abs_y = new_abs_y;
    }

        //set new coordinates to draw
        pos_x = vitares_x/2 - radius;
        pos_y = vitares_y/2 - radius;

        if (abs_x < vitares_x/2)
        {
            pos_x = abs_x - radius;
        }
        else if (abs_x > (level->mapres_x - vitares_x/2))
        {
            pos_x = abs_x - level->map_max_x - radius;
        }

        if (abs_y < vitares_y/2)
        {
            pos_y = abs_y - radius;
        }

        else if (abs_y > (level->mapres_y - vitares_y/2))
        {
            pos_y = abs_y - level->map_max_y - radius;
        }

        level->player_pos_y = abs_y;
        level->player_pos_x = abs_x;


        //fire

        position = gun->act(position, angle);
        set_sprite(position);





}


void Player::calc_stick_rad(float x, float y)
{
    float r = sqrt(x*x + y*y);
    sin_a = y/r;
    cos_a = x/r;
}

Player::~Player()
{
    //dtor
    if (gun)
    {
        delete gun;
    }
}
