#ifndef NEARESTPOINT_H
#define NEARESTPOINT_H

#include <vector>
#include <Point_int.h>


class NearestPoint
{
    public:

        NearestPoint();
        virtual ~NearestPoint();

        //find nearest nav point to a position on the map - returns the position number(index) in target_points vector
        int find_nearest_to(int from_x, int from_y, std::vector<Point_int> target_points);

        //indexes of the nearest points
        int nearest, second_nearest;

    protected:

    private:
};

#endif // NEARESTPOINT_H
