#ifndef SPRITE_H
#define SPRITE_H

#include <GamePlayObj.h>


class Sprite : public GamePlayObj
{
    public:
        Sprite();
        Sprite(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0);
        virtual ~Sprite();
        void spritesheet();

        int res_of_spritesheet_x;
        int res_of_spritesheet_y;
        void sprite_coord_calc(int num);

    protected:

    private:
};

#endif // SPRITE_H
