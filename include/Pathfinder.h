#ifndef PATHFINDER_H
#define PATHFINDER_H


class Pathfinder
{
    public:
        Pathfinder();
        Pathfinder(int x1, int y1, int x2, int y2);
        ~Pathfinder();

        void reinit(int x1, int y1, int x2, int y2);

        void reset();

        int current_x, current_y, target_x, target_y;

        //for y=ax+b
        float a_x, b_x;

        //for x=ay+b
        float a_y, b_y;

        //flag for vertical or horizontal lines.
        bool vertical,
             horizontal;

        void calc_path(int x1, int y1, int x2, int y2);

    protected:

    private:
};

#endif // PATHFINDER_H
