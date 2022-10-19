#include "ArrayFiller.h"
#include "Navigator.h"

ArrayFiller::ArrayFiller()
{
    do_job = &ArrayFiller::do_nothing;
    set_coord(0, 0, 149, 149);
    //ctor
}

bool ArrayFiller::run_tests(int x, int y)
{
   (this->*do_job) (x, y);

   if (x == x_end && y == y_end)
   {
       do_job = &ArrayFiller::do_nothing;
       processing = default_proccessing;
   }
   return 0;
}


void ArrayFiller::call_owner_and_fill(Navigator *own, std::int16_t v)
{
    filling_value = v;
    m_owner = own;
    do_job = &ArrayFiller::call_owner;
    scan_array();

}

void ArrayFiller::call_owner(int x, int y)
{
    if (m_owner->approved(x , y))
    {
        fill_element(x, y);
    }

}


void ArrayFiller::fill_element(int to_, int from_)
{
   (*array1)[to_][from_] = filling_value;
}

void ArrayFiller::fill_all(std::int16_t (*arr)[150][150], std::int16_t v)
{
    array1 = arr;
    //array_set = true;
    filling_value = v;
    do_job = &ArrayFiller::fill_element;
    scan_array();
}



void ArrayFiller::set_compare()
{

}
void ArrayFiller::set_array (LevelData *lev)
{
   level1 = lev;
   set_coord(0, 0 , lev->number_of_points - 1, lev->number_of_points - 1);
   //array1 = &lev->path;
   array_set = true;

}
void ArrayFiller::set_ref_array (LevelData *lev)
{
   level2 = lev;
   //array2 = &lev->path;
}

void ArrayFiller::show_array(std::int16_t (*arr)[150][150])
{
    if (!array_set)
    {
        std::cout << "Warning! Array is not set" << std::endl;
        return;
    }

    for (int i = x_start; i <= x_end; i++)
   {
       for (int k = y_start; k <= y_end; k++)
       {

       std::cout << (*arr)[i][k] << " ";

       }
       std::cout << std::endl;
   }
}

void ArrayFiller::show_array()
{
    if(array1) show_array(array1);

}

bool ArrayFiller::exec()
{
    if (!array_set)
    {
        std::cout << "Array is not set" << std::endl;
        return 0;
    }
    scan_array();

    return 0;
}

void ArrayFiller::do_nothing(int v, int w)
{

}
ArrayFiller::~ArrayFiller()
{
    //dtor
}
