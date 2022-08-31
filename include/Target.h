#ifndef TARGET_H
#define TARGET_H

#include "LevelMap.h"
#include "Entity.h"
#include "LineVec.h"


class Target
{
    public:
        Target();
        Target(LevelMap *mymap);
        bool visible(float abs_x, float abs_y);
        bool direct_path_available (float abs_x, float abs_y, float radius);
        float distance(float abs_x, float abs_y);

        Entity *player;

    protected:

    private:
        LevelMap *level;

        bool right_visible, left_visible;
        bool side_visible (const LineVec &aux_vec);
        LineVec direct_line;


};

#endif // TARGET_H
