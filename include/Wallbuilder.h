#ifndef WALLBUILDER_H
#define WALLBUILDER_H
#include <array>


class Wallbuilder
{
    private:
        static const unsigned int max_array_size = 50;
        unsigned int array_size;

        // walls coordinates
        std::array<int, max_array_size> x_start;
        std::array<int, max_array_size> y_start;
        std::array<int, max_array_size> x_end;
        std::array<int, max_array_size> y_end;

    public:
        Wallbuilder();

        Wallbuilder(int level);

        ~Wallbuilder();


        // for an equation of y=ax+b type
        float a [max_array_size];
        float b [max_array_size];

        void calc_ab (unsigned int wall_num);

        bool pos_valid(int x0, int y0, int radius);

        bool visible(int x1, int y1, int x2, int y2);


    protected:

    private:
    float y_intersec, x_intersec;

};

#endif // WALLBUILDER_H
