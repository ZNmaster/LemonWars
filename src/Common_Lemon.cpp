#include "Common_Lemon.h"
#include "Splash.h"

Common_Lemon::Common_Lemon()
{
    //ctor
}

Common_Lemon::Common_Lemon(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : NPC::NPC(filename, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{

    lemon_init();

}

Common_Lemon::Common_Lemon(vita2d_texture *im, vita2d_texture *blood, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0)
               : NPC::NPC(im, mymap, num_horizontal_sprites,
                                      num_vertical_sprites, x0, y0)
{

    juice = blood;
    lemon_init();
}

void Common_Lemon::lemon_init()
{

    angle = 0;

    set_roam();

    sprite_change_delay = 80;
    last_sprite = 10;

}


void Common_Lemon::go_move()
{

  (this->*carry_on) ();

  calc_screen_pos();
}

void Common_Lemon::hit(int hitpoints, float projectile_angle, int x, int y)
{
    if (!is_hit)
    {
        is_hit = 1;
        move_it = 1;
        hit_angle = projectile_angle;
        splash_x = x;
        splash_y = y;
        carry_on = &Common_Lemon::finish;
    }
}

void Common_Lemon::layer_moved(std::vector<Entity *> &target_lay)
{
    Splash *lemonjuice = new Splash(juice, level, 2, 3, splash_x, splash_y, hit_angle);
    target_lay.push_back(lemonjuice);

    move_it = 0;
    sprite_num = 3;
    set_sprite(sprite_num);
    explosion_timer.delay_mills(80);

    carry_on = &NPC::start_animation;

    level->bodycount++;

    if(level->killstreak_timer.expired())
    {
        level->killstreak = 0;
        level->killstreak_timer.delay_mills(1000);
    }
    else
    {
        level->killstreak++;
        level->killstreak_timer.delay_mills(1000);
    }

}


Common_Lemon::~Common_Lemon()
{
    //dtor
}
