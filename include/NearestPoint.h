#ifndef NEARESTPOINT_H
#define NEARESTPOINT_H

#include <vector>
#include <Point_int.h>


class NearestPoint
{
    public:
        NearestPoint();
        virtual ~NearestPoint();
        int find_nearest_to(int from_x, int from_y, std::vector<Point_int> target_points);
        int nearest, second_nearest;

    protected:

    private:
};

#endif // NEARESTPOINT_H
