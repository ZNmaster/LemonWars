#ifndef LINE_H
#define LINE_H


class Line
{
    public:
        Line();
        Line(float x1, float y1, float x2,  float y2);
        void calcline(float x1, float y1, float x2,  float y2);
        static float length (float x1, float y1, float x2,  float y2);
        float length (float dx, float dy);
        virtual ~Line();

        //flag for vertical or horizontal lines.
        bool vertical,
             horizontal;

        //line parametres
        float delta_x, delta_y;
        float sin_a, cos_a;
        float len;

        float x_start, y_start,
              x_end, y_end;

    protected:


    private:

};

#endif // LINE_H
