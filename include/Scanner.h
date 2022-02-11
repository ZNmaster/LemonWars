#ifndef SCANNER_H
#define SCANNER_H

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
                    fire_pressed,
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


        unsigned int hyst, stick_zero, stick_zero_rx, stick_zero_ry, stick_zero_lx, stick_zero_ly;


        void Scan();


    protected:

    private:

        Point_int read_stick(unsigned int x, unsigned int y);
        void calc_stick_relative(Point_int stick, float &stick_x, float &stick_y, bool &stick_moved);

        //the number of pressed D-pad buttons
        int count_pressed;


};

#endif // SCANNER_H
