#ifndef ARRAYSEARCH_H
#define ARRAYSEARCH_H

#include <vector>


class ArraySearch
{
    public:
        ArraySearch ();
        ArraySearch (int coordX_start, int coordY_start, int coordX_end, int coordY_end);

        virtual bool scan_array();
        virtual bool run_tests();
        virtual bool run_tests(int x);
        virtual bool run_tests(int x, int y);
        virtual ~ArraySearch();

        std::vector<int> visible_point_x, visible_point_y;

    protected:

    private:
        int x_start, y_start, x_end, y_end;
};

#endif // ARRAYSEARCH_H
