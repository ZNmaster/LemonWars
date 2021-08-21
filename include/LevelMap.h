#ifndef LEVELMAP_H
#define LEVELMAP_H

#include <GamePlayObj.h>


class LevelMap : public GamePlayObj
{
    public:
        LevelMap();
        LevelMap(const char *filename);
        virtual ~LevelMap();
        bool valid_pos(int abs_x, int abs_y, int radius);
        int mapres_x,
            mapres_y;
        void set_map_res();
        void go_move();


    protected:

    private:
};

#endif // LEVELMAP_H
