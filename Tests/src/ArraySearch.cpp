#include "ArraySearch.h"
#include <utility>
#include <iostream>

ArraySearch::ArraySearch() : ArraySearch::ArraySearch (0, 0, 1, 1)
{
    //ctor
}

ArraySearch::ArraySearch (int coordX_start, int coordY_start, int coordX_end, int coordY_end)
                         : x_start(coordX_start),
                           y_start(coordY_start),
                           x_end(coordX_end),
                           y_end(coordY_end)
{
   if ((x_start < 0) || (x_end < 0) || (y_start < 0) || (y_end < 0))
   {
       std::cout << "Negative coordinates " << x_start << ", " << y_start << ", " << x_end << ", " <<y_end << std::endl;
       return;
   }

   if (x_start > x_end) std::swap(x_start, x_end);
   if (y_start > y_end) std::swap(y_start, y_end);
   //scan_array();
}

bool ArraySearch::run_tests()
{
return 0;

}

bool ArraySearch::scan_array()
{

int progress = 0;

std::cout << "\r\nProcessing array... " << progress << "% done. ";

const int delta_x = x_end - x_start;
const int delta_y = y_end - y_start;

const int arraySize = delta_x * delta_y;

if (arraySize <= 0) std::cout << "Error: array size is " << arraySize << std::endl;

for (int i = x_start; i <= x_end; i++)
   {
       for (int k = y_start; k <= y_end; k++)
       {
           int temp_prog = (i * k)*100/arraySize;
           //std::cout << "\r" << temp_prog << "% done. ";
           if (temp_prog > progress)
           {
               progress = temp_prog;
               std::cout << "\rProcessing array... " << progress << "% done. ";
           }
       run_tests();

       }
   }
   // fill the image with color
   std::cout << "\rProcessing array... 100% done. \r\n";



return 0;


}

ArraySearch::~ArraySearch()
{
    //dtor
}
