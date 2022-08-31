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

