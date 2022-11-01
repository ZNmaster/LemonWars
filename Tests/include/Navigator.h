#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <vector>
#include "ArrayFiller.h"
#include "Target.h"
#include "Line.h"



class Navigator
{
    public:
        Navigator();
        Navigator(const char *LevelDataFilename);
        bool Create();

        void Load_Data (LevelData &dat, const char *LevelDataFilename);

        virtual ~Navigator();

        bool approved (int to_, int from_);

        //checks navigation possibilities between any 2 points
        bool path_available(int to_, int from_);

        ArrayFiller a;

        LevelMap *level = nullptr;
        Target target_to_chase;




    protected:

    private:
        LevelData level1,
                  level2;

        static int constexpr Y_max = 1940;
        int X_size;
        std::int8_t (*access_map)[Y_max];
        void set_accessible (int x, int y);

        void reset_access_map();

        bool accessible(int x1, int y1, int x2, int y2);

        int rec = 0;

        void create_rectangles();
        std::vector<Line> rectangles;




        std::array<int, 150> copies;

        int calc_path();

};

#endif // NAVIGATOR_H
