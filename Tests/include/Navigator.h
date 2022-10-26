#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include "ArrayFiller.h"
#include "Target.h"


class Navigator
{
    public:
        Navigator();
        Navigator(const char *LevelDataFilename);
        bool Create();

        void Load_Data (LevelData &dat, const char *LevelDataFilename);

        virtual ~Navigator();

        bool approved (int to_, int from_);

        ArrayFiller a;

        LevelMap *level = nullptr;
        Target target_to_chase;

        LevelData level1,
                  level2;



    protected:

    private:



        std::array<int, 150> copies;

        int calc_path();

};

#endif // NAVIGATOR_H
