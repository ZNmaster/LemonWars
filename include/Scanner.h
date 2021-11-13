#ifndef SCANNER_H
#define SCANNER_H

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/touch.h>

#include "Point_int.h"

class Scanner
{
    public:
        Scanner();
        ~Scanner();

        static bool up_pressed,
                    down_pressed,
                    right_pressed,
                    left_pressed,
                    start_pressed,
                    select_pressed,
                    go_pressed,
                    pad_multiple_pressed,
                    stick_nav,
                    left_stick_moved,
                    right_stick_moved,
                    front_touch;

        // touch point coordinates
        static int front_touch_point_x, front_touch_point_y;

        //relative stick readings
        static float lstick_x, lstick_y, rstick_x, rstick_y;



        void ResetAll();

        SceCtrlData pad;
        SceTouchData touch;

        unsigned int hyst, stick_zero;


        void Scan();


    protected:

    private:

        Point_int read_stick(unsigned int x, unsigned int y);


};

#endif // SCANNER_H
