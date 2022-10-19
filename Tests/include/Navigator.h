#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include "ArrayFiller.h"


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



    protected:

    private:
        LevelData level1,
                  level2;
};

#endif // NAVIGATOR_H
