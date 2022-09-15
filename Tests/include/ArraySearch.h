#ifndef ARRAYSEARCH_H
#define ARRAYSEARCH_H


class ArraySearch
{
    public:
        ArraySearch ();
        ArraySearch (int coordX_start, int coordY_start, int coordX_end, int coordY_end);

        virtual bool scan_array();
        virtual bool run_tests();
        virtual ~ArraySearch();

    protected:

    private:
        int x_start, y_start, x_end, y_end;
};

#endif // ARRAYSEARCH_H
