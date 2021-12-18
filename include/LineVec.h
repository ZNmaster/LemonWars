#ifndef LINEVEC_H
#define LINEVEC_H

#include "Point_float.h"
#include "Angle.h"
#include "Line.h"

class LineVec : public Line, public Angle
{
    public:
        LineVec();
        LineVec(Point_float end_point);
        LineVec(Point_float start_point, Point_float end_point);
        LineVec(float length, float rad);
        LineVec(Point_float start_point, float length, float rad);

        void calcline(float length, float rad);
        //void calcangle();


        float angle;
        //const float pi = 3.1415926;

        ~LineVec();
    protected:

    private:
};

#endif // LINEVEC_H
