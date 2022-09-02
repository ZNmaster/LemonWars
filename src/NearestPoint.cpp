#include "NearestPoint.h"
#include "Line.h"

NearestPoint::NearestPoint()
{
    //ctor
}

int NearestPoint::find_nearest_to(int from_x, int from_y, std::vector<Point_int> target_points)
{
     float ref_dist = 99000;
     float ref_dist_sec = 99000;

     for (std::vector<Point_int>::size_type i = 0; i < target_points.size(); i++)
     {
       float dist = Line::length(from_x, from_y, target_points[i].x, target_points[i].y);
       if (dist <= ref_dist)
       {
           ref_dist_sec = ref_dist;
           ref_dist = dist;
           third_nearest = second_nearest;
           second_nearest = nearest;
           nearest = i;
       }
       else if(dist<=ref_dist_sec)
       {
           ref_dist_sec = dist;
           third_nearest = second_nearest;
           second_nearest = i;
       }

    }

  return nearest;
}

NearestPoint::~NearestPoint()
{
    //dtor
}
