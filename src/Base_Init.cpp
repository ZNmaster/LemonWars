#include "Base_Init.h"
#include "Scanner.h"
#include "Letter.h"
#include <cmath>


Base_Init::Base_Init()
{
    grid_activated = 0;
    rad = 0;
    //ctor
}

void Base_Init::GPU_init(unsigned int megabytes)
{
    // initializing libvita and setting background color
    vita2d_init_advanced(megabytes * 1024 * 1024);
	vita2d_set_clear_color(RGBA8(0x40, 0x40, 0x40, 0xFF));
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
    //vita2d_free_pvf(pvf);
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

    /*size_t stack_size = sceKernelGetThreadStackFreeSize(0);
    std::stringstream o;
    o << "Stack available: " << stack_size;

    vita2d_pvf_draw_text(pvf, 50, 50, RGBA8(0,255,0,255), 1.0f, o.str().c_str());*/

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
               // check if the object is partial and scaled
               if (objimage->scaled)
               {
                   vita2d_draw_texture_part_scale(objimage->image, objimage->pos_x, objimage->pos_y,
                                        objimage->part_x, objimage->part_y,
                                        objimage->res_of_sprites_x,
                                        objimage->res_of_sprites_y, objimage->k_x, objimage->k_y);
               }

               else if (objimage->angle != 0)
               {
                   vita2d_draw_texture_part_scale_rotate(objimage->image, objimage->pos_x+(objimage->res_of_sprites_x / 2), objimage->pos_y+(objimage->res_of_sprites_y / 2),
                                        objimage->part_x, objimage->part_y,
                                        objimage->res_of_sprites_x,
                                        objimage->res_of_sprites_y, 1, 1, objimage->angle);
               }

               // check if the object is only partial
               else

               {
                   vita2d_draw_texture_part(objimage->image, objimage->pos_x, objimage->pos_y,
                                        objimage->part_x, objimage->part_y,
                                        objimage->res_of_sprites_x,
                                        objimage->res_of_sprites_y);


               }
            }
            // check if the object needs the waved effect enabled
            else if (objimage->waved)
               {
                   draw_texture_waved(objimage->image,objimage->pos_x, objimage->pos_y, objimage->k_x, objimage->k_y);
               }
               // for everything else don't apply anything and draw the whole image
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
    int k = 4;
    int res_x = 128;
    //int res_y = 256;
    int num_h = 8;
    int num_v = 16;
    int x0 = x;
    int y0 = y;
    int offset = res_x / num_h;

    for(unsigned int i = 0; i<text.length(); i++)
    {
        Letter *title = new Letter(filename, num_h, num_v,
                                   (x0+i*offset*k), y0, (int)text[i]);
        title->k_x = k;
        title->k_y = k;
        title->scaled = 1;
        title->set_effect(1, 1, i);
        obj.push_back (title);
    }


}

void Base_Init::draw_texture_waved(vita2d_texture *image, int pos_x, int pos_y, int scale_x, int scale_y)
{


		size_t nslices = 50;
		size_t n_tvertices = 6 * nslices;
		vita2d_texture_vertex *tvertices = (vita2d_texture_vertex *)vita2d_pool_memalign(
			n_tvertices * sizeof(vita2d_texture_vertex),
			sizeof(vita2d_texture_vertex));

		for (int slice=0; slice<nslices; slice++) {
			float a = (float)slice/(float)nslices;
			float b = (float)(slice+1)/(float)nslices;

			vita2d_texture_vertex *v = &tvertices[slice*6];
			(v++)->u = a; (v++)->u = a; (v++)->u = b;
			(v++)->u = a; (v++)->u = b; (v++)->u = b;
		}



        for (int i=0; i<n_tvertices; ++i) {


            tvertices[i].v = i % 2;
			tvertices[i].x = pos_x*1.f + scale_x*1.f * tvertices[i].u + 5.f * sinf(tvertices[i].u*(3.f+20.f*fabsf(sinf(rad*0.1f)))+rad);
			tvertices[i].y = pos_y*1.f + scale_y*1.f * tvertices[i].v + 5.f * sinf(tvertices[i].u*(3.f+20.f*fabsf(sinf(rad*0.1f)))+rad);
			tvertices[i].z = 0.5f;
		}

		vita2d_draw_array_textured(image, SCE_GXM_PRIMITIVE_TRIANGLES, tvertices, n_tvertices, RGBA8(0xFF, 0xFF, 0xFF, 0xFF));

		rad += delta_rad;
		if ((rad > 3.2f) || (rad < 0.f))
        {
            delta_rad = -delta_rad;
        }

}


Base_Init::~Base_Init()
{
    //dtor
}
