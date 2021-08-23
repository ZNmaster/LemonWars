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


        virtual void go_move();

        int map_min_x,
            map_min_y,
            map_max_x,
            map_max_y;

        int player_pos_x,
            player_pos_y;





    protected:

    private:
};

#endif // LEVELMAP_H
