#ifndef VISCHECKER_H
#define VISCHECKER_H

#include "ArraySearch.h"

#include "Wallbuilder.h"


class VisChecker : public ArraySearch
{
    public:
        VisChecker();
        VisChecker(int coordX_start, int coordY_start, int coordX_end, int coordY_end);

        virtual ~VisChecker();

        virtual bool run_tests(int x, int y);


    protected:

    private:

        Wallbuilder walls;
};

#endif // VISCHECKER_H
