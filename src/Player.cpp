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
    move_timer.stop();
    move_delta = (int)(speed*move_timer.duration_float+1);
    move_timer.start();

    //move_delta = 5;
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

        pos_x = abs_x - radius;
        pos_y = abs_y - radius;

}

Player::~Player()
{
    //dtor
}
