#ifndef SOUNDS_H
#define SOUNDS_H



class Sounds
{
    public:
        Sounds();
        virtual ~Sounds();

        void play_fire_sound();
        void play_projectile_explosion_sound();
        void play_floating_lemon_hit();
        void play_lemon_juice();
        void play_lemonade();
        void play_ezpz();

        void play_beep();
        void play_beep2();



    protected:

    private:


        int gunfire_sound_id,
            projectile_explosion_sound_id,
            floating_lemon_hit_sound_id;

};

#endif // SOUNDS_H
