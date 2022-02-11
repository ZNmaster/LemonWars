#ifndef GAMEPLAYOBJ_H
#define GAMEPLAYOBJ_H

#include <Entity.h>


class GamePlayObj : public Entity
{
    public:
        GamePlayObj();
        GamePlayObj(const char *filename);

        /* !!!!!!!!!!!!!!!!!!!!! be careful with this constructor. For some reason GPU crashes if you pass the
                                 pointer of the texture to create an object. To avoid this you must to load the texture TWICE!!!!!!!!!!!!!*/
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
        bool external_image;
};

#endif // GAMEPLAYOBJ_H
