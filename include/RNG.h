#ifndef RNG_H
#define RNG_H


class RNG
{
    public:
        RNG();
        ~RNG();

        int int_random(int x_max);

        int int_random(int x_max, int x_min);

    protected:

    private:
};

#endif // RNG_H
