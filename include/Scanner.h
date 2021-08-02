#ifndef SCANNER_H
#define SCANNER_H

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

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
                    select_pressed;

        void ResetAll();
        void Scan();
        SceCtrlData pad;

    protected:

    private:
};

#endif // SCANNER_H
