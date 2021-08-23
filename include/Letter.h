#ifndef LETTER_H
#define LETTER_H

#include <Sprite.h>


class Letter : public Sprite
{
    public:
        Letter();
        Letter(const char *filename, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, int letter);
        int char_pos_calc(int letter_ascii);
        bool effect_jump;

        //variables for effect
        int x0, y0;
        int delta;
        int direction;

        void set_effect(int effect_num, int delta1, int i);


        void go_move();
        virtual ~Letter();

    protected:

    private:
};

#endif // LETTER_H
