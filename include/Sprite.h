#ifndef SPRITE_H
#define SPRITE_H

#include <GamePlayObj.h>


class Sprite : public GamePlayObj
{
    public:
        Sprite();
        Sprite(const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, char letter);
        virtual ~Sprite();
        void spritesheet();
        int res_of_sprites_x;
        int res_of_sprites_y;
        int res_of_spritesheet_x;
        int res_of_spritesheet_y;
        int char_num_calc(char letter);
        void char_coord_calc(int num);

    protected:

    private:
};

#endif // SPRITE_H
