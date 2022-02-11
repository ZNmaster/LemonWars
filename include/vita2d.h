#ifndef VITA2D_H
#define VITA2D_H

#include "vita2d_texture.h"

vita2d_texture *vita2d_load_PNG_file(const char *filename);

vita2d_texture *vita2d_load_PNG_buffer(const void *buffer);

unsigned int vita2d_texture_get_width(const vita2d_texture *texture);

unsigned int vita2d_texture_get_height(const vita2d_texture *texture);

void vita2d_free_texture(vita2d_texture *texture);

vita2d_texture *vita2d_create_empty_texture(unsigned int w, unsigned int h);


#endif // VITA2D_H
