#ifndef WALLBUILDER_H
#define WALLBUILDER_H
#include <array>
#include <vector>
#include "LineEq.h"
#include "Point_int.h"
#include "LevelData.h"


class Wallbuilder
{
    private:
        static const unsigned int max_array_size = 50;
        int array_size;

        // walls coordinates
        std::array<int, max_array_size> x_start;
        std::array<int, max_array_size> y_start;
        std::array<int, max_array_size> x_end;
        std::array<int, max_array_size> y_end;

    public:
        Wallbuilder();

        Wallbuilder(const LevelData &data);

        ~Wallbuilder();


        // for an equation of y=ax+b type
        float a [max_array_size];
        float b [max_array_size];

        //void calc_ab (unsigned int wall_num);

        bool pos_valid(int x0, int y0, int radius);

        //check the visibility between 2 points on the map
        bool visible(int x1, int y1, int x2, int y2);

        //check intersection points
        bool intersected(int x1, int y1, int x2, int y2);
        std::vector<Point_int> intersection_points;
        //line of view

        LineEq AB;




    protected:

    private:
        bool intersection(int x1, int y1, int x2, int y2, bool visibility_only);


};

#endif // WALLBUILDER_H
