#ifndef BASE_INIT_H
#define BASE_INIT_H
#include <vector>

#include "Timer.h"
#include "Entity.h"

#include <vita2d.h>


class Base_Init
{
    public:
        Base_Init();
        ~Base_Init();
        void GPU_init();
        void GPU_finish();

        //vita2d_pgf *pgf;
        vita2d_pvf *pvf;
        float rad = 0.0f;
        bool grid_activated;

        void draw_grid();
        void draw_grid(int stride);

        bool draw_frame(std::vector<Entity *> obj);
        void free_textures(std::vector<Entity *> &obj);


        Timer grid_toggle_timer;



    protected:

    private:

};

#endif // BASE_INIT_H
