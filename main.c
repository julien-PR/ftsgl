#define LIBSTR_IMPLEMENTATION
#include "libftsgl.h"
#include "ftsglVao.h"

int	width = 540;
int	height = 540;

int	main(void)
{
	t_ftsglWindow	*window = ftsglWindowCreate(width, height, "ftsgl");
	if (NULL == window)
		return (FTSGL_FAILURE);

	t_ftsglRenderer	*renderer = ftsglRendererCreate(window);
	glfwSetWindowUserPointer(window->win, renderer);

	int	x = 0;
	while(!glfwWindowShouldClose(window->win))
	{
		glfwPollEvents();
		ftsglRendererSetPixelColor(renderer, x % window->base_width, x / window->base_width, (t_ftsglVec3){1, 0, 0});
		++x;
		if (x >= window->base_width * window->base_height)
			x = 0;
		ftsglRendererPresent(renderer);
	}
	ftsglRendererDestroy(renderer);
	ftsglWindowDestroy(window);
	return (FTSGL_SUCCESS);
}
