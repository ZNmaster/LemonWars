#ifndef ANGLE_H
#define ANGLE_H


class Angle
{
    public:
        Angle();

        static constexpr float pi = 3.1415926;

        static float calcangle(float sin_a, float cos_a);


        virtual ~Angle();

    protected:

    private:
};

#endif // ANGLE_H
