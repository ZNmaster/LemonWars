#ifndef LINE_H
#define LINE_H


class Line
{
    public:
        Line();
        Line(float x1, float y1, float x2,  float y2);

        //line parameters calc
        void calcline(float x1, float y1, float x2,  float y2);

        //length calc between 2 points
        static float length(float x1, float y1, float x2,  float y2);

        //length calc by delta
        float length(float dx, float dy);

        //set vertical or horizontal flags
        void setVH();

        ~Line();

        //flag for vertical or horizontal lines.
        bool vertical,
             horizontal;

        //line parameters
        float delta_x, delta_y;
        float sin_a, cos_a;
        float len;

        float x_start, y_start,
              x_end, y_end;

    protected:


    private:

};

#endif // LINE_H
