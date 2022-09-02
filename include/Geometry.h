#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Point_int.h"
#include "Point_float.h"


class EPoint_int : public Point_int
{
    public:
        EPoint_int();
        EPoint_int(unsigned int x1, unsigned int y1);

    protected:

    private:
};

class EPoint_float : public Point_float
{
    public:
        EPoint_float();
        EPoint_float(float x1, float y1);

    protected:

    private:
};

#endif // GEOMETRY_H
