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
                    left_stick_moved,
                    right_stick_moved,
                    front_touch;


        void ResetAll();

        SceCtrlData pad;
        SceTouchData touch;

        Point_int front_touch_point;

        void Scan();


    protected:

    private:

};

#endif // SCANNER_H
