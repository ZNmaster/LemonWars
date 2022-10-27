#ifndef ARRAYFILLER_H
#define ARRAYFILLER_H
#include <iostream>
#include <sstream>
#include <array>
#include <vector>

#include "ArraySearch.h"
#include "LevelData.h"
#include "Geometry.h"

class Navigator;


class ArrayFiller : public ArraySearch
{
    public:
        ArrayFiller();
        void do_nothing(int v, int w);

        std::int16_t filling_value;

        LevelData *level1;
        LevelData *level2;

        std::int16_t (*array1)[150][150] = nullptr;
        std::int16_t (*array2)[150][150] = nullptr;

        std::vector<EPoint_int> points;



        //pointer to the current job
        void (ArrayFiller::*do_job) (int, int);

        //called for each element from arraysearch
        virtual bool run_tests(int x, int y);

        bool exec();

        //set functions
        void fill_all(std::int16_t (*arr)[150][150], std::int16_t v);
        void show_array(std::int16_t (*arr)[150][150]);
        void call_owner_and_fill(Navigator *own, std::int16_t v);
        void call_owner(int x, int y);
        void show_array();
        //void compare(LevelData *lev);
        void set_array (LevelData *lev);
        void set_ref_array (LevelData *lev);
        void run();
        void find_copies(std::int16_t (*arr)[150][150], std::array<int, 150> &copies);
        void show_columns (int a, int b = -1, int c = -1, int d = -1, int e = -1, int f = -1, int g = -1);
        void copy_array (std::int16_t (*source)[150][150], std::int16_t (*dest)[150][150]);
        std::int64_t array_add (std::int16_t (*arr)[150][150]);
        //compare 2 arrays
        void compare(std::int16_t (*arr1)[150][150], std::int16_t (*arr2)[150][150]);
        //compare default array with arr2
        void compare(std::int16_t (*arr2)[150][150]);

        void check_nav_table();

        virtual ~ArrayFiller();

        unsigned int recalc_distance();


    protected:

    private:
        bool array_set = false;
        Navigator *m_owner = nullptr;
        void compare_element(int to_, int from_);
        void fill_element(int to_, int from_);
        void navigate(int to_, int from_);
        void set_default();
        void dist(int to_, int from_);
        void direct_copy (int i, int k);
        float nav_dist(std::int16_t point_1, std::int16_t point_2);
        bool array_not_set();

        std::stringstream o2;
        std::int16_t (*default_array1)[150][150] = nullptr;
        std::int16_t (*default_array2)[150][150] = nullptr;
        int default_x, default_y;
};

#endif // ARRAYFILLER_H
