#ifndef LETTER_H
#define LETTER_H

#include <Sprite.h>


class Letter : public Sprite
{
    public:
        Letter();
        Letter(const char *filename, int res_x, int res_y, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, int letter);
        int char_pos_calc(int letter_ascii);

        virtual ~Letter();

    protected:

    private:
};

#endif // LETTER_H
