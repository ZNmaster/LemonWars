#ifndef GAMEPLAYOBJ_H
#define GAMEPLAYOBJ_H

#include <Entity.h>


class GamePlayObj : public Entity
{
    public:
        GamePlayObj();
        GamePlayObj(const char *filename);
        GamePlayObj(vita2d_texture *im);
        virtual ~GamePlayObj();



        //ressolution of the texture loaded
        //used for spritesheet resolution
        int loaded_image_res_x,
            loaded_image_res_y;


        //for moving objects
        bool started;//if moving enabled
        int delta;// moving step

        void set_res();

    protected:

    private:
        void set_texture();
};

#endif // GAMEPLAYOBJ_H
