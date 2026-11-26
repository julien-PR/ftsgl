#ifndef FTSGL_IMAGE_H
# define FTSGL_IMAGE_H

# include <stdlib.h>
# define GLEW_STATIC
# include <GL/glew.h>
# include "libmem.h"

typedef struct s_ftsglImage
{
	int		width;
	int		height;
	uint8_t	bit_depth;
	uint8_t	channels;
	void	*pixels;
}	t_ftsglImage;

t_ftsglImage	*ftsglImageCreate(void *pixels, int width, int height, uint8_t bit_depth, uint8_t channels);

void	ftsglImageDestroy(t_ftsglImage *image);

#endif
