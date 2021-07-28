#ifndef BASE_INIT_H
#define BASE_INIT_H
#include <vita2d.h>


class Base_Init
{
    public:
        Base_Init();
        ~Base_Init();
        void GPU_init();
        void GPU_finish();
        vita2d_pvf *pvf;


    protected:

    private:

};

#endif // BASE_INIT_H
