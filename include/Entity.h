#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        Entity(int a);
        virtual ~Entity();
        int abs_x, abs_y;
        float distance(int x1, int y1);
        virtual void go_move();

    protected:

    private:
};

#endif // ENTITY_H
