#ifndef FTSGL_IMAGE_H
# define FTSGL_IMAGE_H

# include <stdlib.h>
# define GLEW_STATIC
# include <GL/glew.h>
# include "libstr.h"

typedef struct s_ftsglImage
{
	int		width;
	int		height;
	void	*pixels;
}	t_ftsglImage;

t_ftsglImage	*ftsglImageCreate(int width, int height, void *pixels);

void	ftsglImageDestroy(t_ftsglImage *image);

#endif
