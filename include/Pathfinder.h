#ifndef PATHFINDER_H
#define PATHFINDER_H


class Pathfinder
{
    public:
        Pathfinder();
        Pathfinder(float x1, float y1, float x2, float y2);
        ~Pathfinder();

        void move_by(float distance);

        // called by constructor and then any time we need to reinit the class
        void reinit(float x1, float y1, float x2, float y2);

        // resets all bool variables
        void reset();

        // current and target coordinates
        int current_x, current_y, target_x, target_y;

        void calc_path(float x1, float y1, float x2, float y2);

        bool arrived;



    protected:

    private:

        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;

        //flag for vertical or horizontal lines.
        bool vertical,
             horizontal;


        float delta_x, delta_y;
        float sin_a, cos_a;

        void go_high(float distance);
        void go_low(float distance);

        void (Pathfinder::*calc_coord) (float);

        void arrival();

};

#endif // PATHFINDER_H
