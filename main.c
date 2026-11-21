#define LIBSTR_IMPLEMENTATION
#include "libftsgl.h"
#include "ftsglVao.h"

int	main(void)
{
	t_ftsglWindow	*window = ftsglWindowCreate(540, 540, "ftsgl");
	if (NULL == window)
		return (FTSGL_FAILURE);

	t_ftsglRenderer	*renderer = ftsglRendererCreate(window);
	if (NULL == renderer)
	{
		ftsglWindowDestroy(window);
		return (FTSGL_FAILURE);
	}
	glfwSetWindowUserPointer(window->win, renderer);

	while(!glfwWindowShouldClose(window->win))
	{
		glfwPollEvents();
		ftsglRendererPresent(renderer);
	}
	ftsglRendererDestroy(renderer);
	ftsglWindowDestroy(window);
	return (FTSGL_SUCCESS);
}
