#ifndef LEVELMAP_H
#define LEVELMAP_H

#include <GamePlayObj.h>


class LevelMap : public GamePlayObj
{
    public:
        LevelMap();
        LevelMap(const char *filename);
        virtual ~LevelMap();

    protected:

    private:
};

#endif // LEVELMAP_H
