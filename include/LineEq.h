#ifndef LINEEQ_H
#define LINEEQ_H

#include <Line.h>


class LineEq : public Line
{
    public:
        LineEq();
        LineEq(float x1, float y1, float x2,  float y2);
        virtual ~LineEq();

        //for y=ax+b
        float a, b;
        void calcfactors();



    protected:

    private:
};

#endif // LINEEQ_H
