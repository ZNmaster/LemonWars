#include "Player.h"
#include "Scanner.h"

Player::Player()
{
    //ctor
}

Player::Player(LevelMap *mymap, const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : Character::Character(filename, res_x, res_y, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{
    speed = 200;
    move_timer.start();
    sprite_coord_calc(0);
    level = mymap;
}

void Player::go_move()
{
    //reset new position
    new_abs_y = abs_y;
    new_abs_x = abs_x;

    move_timer.stop();
    move_delta = (int)(speed*move_timer.duration_float+1);
    move_timer.start();


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

    if (level->valid_pos(new_abs_x, new_abs_y, radius))
    {
        abs_x = new_abs_x;
        abs_y = new_abs_y;
    }

        //set new coordinates to draw
        pos_x = vitares_x/2;
        pos_y = vitares_y/2;

        if (abs_x < vitares_x/2)
        {
            pos_x = abs_x - radius;
        }
        else if (abs_x > (level->mapres_x - vitares_x))
        {
            pos_x = abs_x - level->map_max_x - radius;
        }

        if (abs_y < vitares_y/2)
        {
            pos_y = abs_y - radius;
        }

        else if (abs_y > (level->mapres_y - vitares_y))
        {
            pos_y = abs_y - level->map_max_y - radius;
        }

        level->player_pos_y = abs_y;
        level->player_pos_x = abs_x;


}

Player::~Player()
{
    //dtor
}
