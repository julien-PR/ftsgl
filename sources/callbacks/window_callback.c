#include "libftsgl.h"

void	window_close_callback(GLFWwindow *window)
{
	(void)window;
	printf("Window closed\n");
	return ;
}

void	window_frame_buffer_size_callback(GLFWwindow *window, int w, int h)
{
	(void)window;
	if (width == 0 || height == 0)
		return ;
	glViewport(0, 0, w, h);
	printf("Window resized\n");
	return ;
}
