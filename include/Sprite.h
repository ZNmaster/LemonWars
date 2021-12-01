#ifndef SPRITE_H
#define SPRITE_H

#include <GamePlayObj.h>


class Sprite : public GamePlayObj
{
    public:
        Sprite();
        Sprite(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);


        /* !!!!!!!!!!!!!!!!!!!!! be careful with this constructor. For some reason GPU crashes if you pass the
                                 pointer of the texture to create an object. To avoid this you must to load the texture TWICE!!!!!!!!!!!!!*/
        Sprite(vita2d_texture *im, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);

        virtual ~Sprite();
        void spritesheet();


        //sets the current sprite by its number
        void set_sprite(int num);

    protected:

    private:
        //constructor delegee - sets the sprite resolution and initial screen position
        void set_sprites(int num_horizontal_sprites, int num_vertical_sprites, int x0, int y0);

        //defines if the image texture passed from outside
        bool image_loaded;
        int sprites_x, sprites_y;


};

#endif // SPRITE_H
