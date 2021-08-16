#ifndef BASE_INIT_H
#define BASE_INIT_H
#include <vector>
#include <string>

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
        float rad = 1.f;
        float delta_rad = 0.015f;
        bool grid_activated;

        void draw_grid();
        void draw_grid(int stride);

        bool draw_frame(std::vector<Entity *> obj);
        void free_textures(std::vector<Entity *> &obj);

        void draw_texture_waved(vita2d_texture *image, int pos_x, int pos_y, int scale_x, int scale_y);

        void create_text_from_font(std::string text, int x, int y,
                                   const char *filename, std::vector<Entity *> &obj);

        //vector of pointers to gameplay objects (images)
        std::vector<Entity *> obj;

        Timer grid_toggle_timer;



    protected:

    private:

};

#endif // BASE_INIT_H
