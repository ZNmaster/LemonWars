#ifndef SPLASH_H
#define SPLASH_H

#include <MovObj.h>


class Splash : public MovObj
{
    public:
        Splash();
        Splash(vita2d_texture *im, LevelMap *mymap, int num_horizontal_sprites,
               int num_vertical_sprites, int x0, int y0, float ang);

        virtual void go_move();
        virtual void stop_animation();

        virtual ~Splash();

    protected:

    private:
};

#endif // SPLASH_H
