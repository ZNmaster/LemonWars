#ifndef COMMON_LEMON_H
#define COMMON_LEMON_H

#include <NPC.h>


class Common_Lemon : public NPC
{
    public:
        Common_Lemon();
        Common_Lemon(const char *filename, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);
        Common_Lemon(vita2d_texture *im, vita2d_texture *blood, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        void lemon_init();

        virtual void hit(int hitpoints, float projectile_angle, int x, int y);

        virtual ~Common_Lemon();
        void go_move();

        virtual void layer_moved(std::vector<Entity *> &target_lay);




    protected:

    private:


};

#endif // COMMON_LEMON_H
