#include "ftsglImage.h"

t_ftsglImage	*ftsglImageCreate(int width, int height, void *pixels)
{
	const size_t	size = width * height;
	t_ftsglImage	*image;

	image = malloc(sizeof(t_ftsglImage));
	if (NULL == image)
		return (NULL);
	image->width = width;
	image->height = height;
	image->pixels = calloc(size, 1);
	if (NULL == image->pixels)
	{
		free(image);
		return (NULL);
	}
	strMemCopy(image->pixels, pixels, size);
	return (image);
}

void	ftsglImageDestroy(t_ftsglImage *image)
{
	free(image->pixels);
	free(image);
	return ;
}
