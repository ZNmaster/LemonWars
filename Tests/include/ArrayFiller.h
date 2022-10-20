#ifndef ARRAYFILLER_H
#define ARRAYFILLER_H
#include <iostream>
#include <sstream>

#include "ArraySearch.h"
#include "LevelData.h"

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
        void compare(LevelData *lev);
        void set_array (LevelData *lev);
        void set_ref_array (LevelData *lev);
        void run();

        virtual ~ArrayFiller();



    protected:

    private:
        bool array_set = false;
        Navigator *m_owner = nullptr;
        void compare_element(int to_, int from_);
        void fill_element(int to_, int from_);
        std::stringstream o2;
};

#endif // ARRAYFILLER_H
