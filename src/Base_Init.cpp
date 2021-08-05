#include "Base_Init.h"
#include "Scanner.h"
#include "Letter.h"


Base_Init::Base_Init()
{
    grid_activated = 0;
    //ctor
}

void Base_Init::GPU_init()
{
    // initializing libvita and setting background color
    vita2d_init();
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));

	//pgf = vita2d_load_default_pgf();
	//pvf = vita2d_load_default_pvf();

}
void Base_Init::GPU_finish()
{
    //stop drawing
    vita2d_wait_rendering_done();
    vita2d_fini();
}

void Base_Init::draw_grid()
{
    //draw a grid with stride 100
    draw_grid(100);
}

void Base_Init::draw_grid(int stride)
{

//toggle grid if timer expired
        if (Scanner::select_pressed)
        {
            if (grid_toggle_timer.expired())
            {
                grid_activated = !grid_activated;
                grid_toggle_timer.delay_mills(200);
            }


        }

    if (grid_activated)
  {



    //drawing vertical lines of the grid
    int x_start = stride;


    while(x_start < 960)
    {

    int x_stop = x_start;
    vita2d_draw_line(x_start, 0, x_stop, 544, RGBA8(0, 255, 252, 150));
    x_start = x_start + stride;

    }

    //drawing horizontal lines of the grid
    int y_start = stride;


    while(y_start < 544)
    {

    int y_stop = y_start;
    vita2d_draw_line(0, y_start, 960, y_stop, RGBA8(0, 255, 252, 150));
    y_start = y_start + stride;

    }
  }

}
bool Base_Init::draw_frame(std::vector<Entity *> obj)
{
        //calling funcs at the start of each frame
        vita2d_start_drawing();
		vita2d_clear_screen();


        //taking object pointers one by one and drawing their images
        for (auto objimage : obj)
        {

         //if some object tells us to stop we stop
         if (objimage->terminated)
            {
                return 1;
            }

            if (objimage->partial)
            {
               vita2d_draw_texture_part(objimage->image, objimage->pos_x, objimage->pos_y,
                                        objimage->part_x, objimage->part_y,
                                        objimage->res_of_sprites_x,
                                        objimage->res_of_sprites_y);
            }
            else
            {
                vita2d_draw_texture(objimage->image, objimage->pos_x, objimage->pos_y);
            }


            //calling move method of each object
            objimage->go_move();

        }

        //debug grid
        draw_grid();

        //calling funcs at the end of each frame
        vita2d_end_drawing();
        vita2d_swap_buffers();

        return 0;
}
void Base_Init::free_textures(std::vector<Entity *> &obj)
{

    //deleting one by one game objects
    for (auto objimage : obj)
    {
        delete objimage;
    }
    obj.clear();
}

void Base_Init::create_text_from_font(std::string text, int x, int y,
                                const char *filename, std::vector<Entity *> &obj)
{
    int res_x = 128;
    int res_y = 256;
    int num_h = 8;
    int num_v = 16;
    int x0 = 300;
    int y0 = 50;
    int offset = res_x / num_h;

    for(unsigned int i = 0; i<text.length(); i++)
    {
        Letter *title = new Letter(filename, res_x, res_y, num_h, num_v,
                                   (x0+i*offset), y0, (int)text[i]);
        obj.push_back (title);
    }


}

Base_Init::~Base_Init()
{
    //dtor
}
