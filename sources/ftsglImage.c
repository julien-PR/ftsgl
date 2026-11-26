#include "ftsglImage.h"

t_ftsglImage	*ftsglImageCreate(void *pixels, int width, int height, uint8_t bit_depth, uint8_t channels)
{
	const size_t	img_size = width * height;
	const size_t	pixel_size = channels * (bit_depth >= 8 ? bit_depth / 8 : 1);
	t_ftsglImage	*image;

	image = malloc(sizeof(t_ftsglImage));
	if (NULL == image)
		return (NULL);
	image->width = width;
	image->height = height;
	image->pixels = calloc(img_size, pixel_size);
	if (NULL == image->pixels)
	{
		free(image);
		return (NULL);
	}
	memCopy(image->pixels, pixels, img_size * pixel_size);
	return (image);
}

void	ftsglImageDestroy(t_ftsglImage *image)
{
	free(image->pixels);
	free(image);
	return ;
}
