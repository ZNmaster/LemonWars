#ifndef SCANNER_H
#define SCANNER_H


class Scanner
{
    public:
        Scanner();
        ~Scanner();

        static bool up_pressed, down_pressed, right_pressed, left_pressed, start_pressed;

        void ResetAll();

    protected:

    private:
};

#endif // SCANNER_H
