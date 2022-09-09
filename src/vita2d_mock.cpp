#include "vita2d.h"
#include <iostream>


vita2d_texture *vita2d_load_PNG_file(const char *filename)
{
   std::cout << "file " << filename << " loaded!" << std::endl;
   return new vita2d_texture;
}

vita2d_texture *vita2d_load_PNG_buffer(const void *buffer)
{
   return new vita2d_texture;
}

unsigned int vita2d_texture_get_width(const vita2d_texture *texture)
{
   return 60;
}

unsigned int vita2d_texture_get_height(const vita2d_texture *texture)
{
   return 420;
}

void vita2d_free_texture(vita2d_texture *texture)
{
  std::cout << "texture deleted" << std::endl;
  delete texture;
}

vita2d_texture *vita2d_create_empty_texture(unsigned int w, unsigned int h)
{
   return new vita2d_texture;
}

int vita2d_init_advanced(unsigned int temp_pool_size)
{
    return 0;
}

void vita2d_set_clear_color(unsigned int color)
{

}

vita2d_pvf *vita2d_load_default_pvf()
{

}

int vita2d_init()
{
    return 0;
}

void vita2d_wait_rendering_done()
{

}

int vita2d_fini()
{
    return 0;
}

void vita2d_free_pvf(vita2d_pvf *font)
{

}

void vita2d_draw_line(float x0, float y0, float x1, float y1, unsigned int color)
{

}

void vita2d_start_drawing()
{

}

void vita2d_clear_screen()
{

}

void vita2d_end_drawing()
{

}

void vita2d_swap_buffers()
{

}

int vita2d_pvf_draw_text(vita2d_pvf *font, int x, int y, unsigned int color, float scale, const char *text)
{
    return 0;
}

void vita2d_draw_texture_part(const vita2d_texture *texture, float x, float y, float tex_x, float tex_y, float tex_w, float tex_h)
{

}

void vita2d_draw_texture_part_scale(const vita2d_texture *texture, float x, float y, float tex_x, float tex_y, float tex_w, float tex_h, float x_scale, float y_scale)
{

}

void vita2d_draw_texture_scale_rotate_hotspot(const vita2d_texture *texture, float x, float y, float x_scale, float y_scale, float rad, float center_x, float center_y)
{

}

void *vita2d_pool_memalign(unsigned int size, unsigned int alignment)
{

}

void vita2d_draw_texture_part_scale_rotate(const vita2d_texture *texture, float x, float y, float tex_x, float tex_y, float tex_w, float tex_h, float x_scale, float y_scale, float rad)
{

}

void vita2d_draw_texture(const vita2d_texture *texture, float x, float y)
{

}

void vita2d_draw_array_textured(const vita2d_texture *texture, SceGxmPrimitiveType mode, const vita2d_texture_vertex *vertices, size_t count, unsigned int color)
{

}

