#ifndef BASE_INIT_H
#define BASE_INIT_H

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>


class Base_Init
{
    public:
        Base_Init();
        ~Base_Init();
        void GPU_init();
        void GPU_finish();

        SceCtrlData pad;
        //vita2d_pgf *pgf;
        vita2d_pvf *pvf;
        vita2d_texture *image;
        float rad = 0.0f;
        void draw_grid();
        void draw_grid(int stride);

    protected:

    private:

};

#endif // BASE_INIT_H
