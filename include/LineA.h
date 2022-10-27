#ifndef LINEA_H
#define LINEA_H

#include "LineEq.h"
#include "Point_float.h"


class LineA : public LineEq
{
    public:
        LineA();
        LineA(float x1, float y1, float x2,  float y2);
        void calcABC();
        virtual ~LineA();

        //factors for A1x + B1y = C1 and A2x + B2y = C2
        float A1, B1, C1,
              A2, B2, C2;
        // returns a perpendicular to this line passing via (x1, y1)
        LineA normal(float x1, float y1);
        bool intersection_known;
        Point_float intersection_point;

    protected:

    private:
};

#endif // LINEA_H
