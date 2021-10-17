#ifndef LEVELMAP_H
#define LEVELMAP_H

#include "GamePlayObj.h"
#include "Wallbuilder.h"
#include "MemoryAI.h"


class LevelMap : public GamePlayObj
{
    public:
        static int number_of_enemies;

        LevelMap();
        LevelMap(const char *MapFilename, const char *MemFilename);
        virtual ~LevelMap();

        //position validator
        bool valid_pos(int abs_x, int abs_y, int radius);

        Wallbuilder levelwalls;

        //touch radius of the player
        int touch_radius = 50;

        //nav points memory
        MemoryAI levelmem;


        virtual void go_move();

        // minimum and maximum partial start coordinates of the map (minimums = always zeros)
        int map_min_x,
            map_min_y,
            map_max_x,
            map_max_y;

        //the copies of loaded_image_res just for convinience
        int mapres_x,
            mapres_y;

        //position of the player
        int player_pos_x,
            player_pos_y;



    protected:

    private:


};

#endif // LEVELMAP_H
