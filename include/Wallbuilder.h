#ifndef WALLBUILDER_H
#define WALLBUILDER_H


class Wallbuilder
{
    public:
        Wallbuilder();
        ~Wallbuilder();
        static const unsigned int array_size = 100;
        unsigned int x_start [array_size];
        unsigned int y_start [array_size];
        unsigned int x_end [array_size];
        unsigned int y_end [array_size];
        float a [array_size];
        float b [array_size];

        void calc_ab (unsigned int wall_num);

    protected:

    private:
};

#endif // WALLBUILDER_H
