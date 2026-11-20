#include "ftsglWindow.h"
#include "ftsglRenderer.h"

static void	error_callback(int error, const char *description)
{
	fprintf(stderr, "Error %d : %s\n", error, description);
	return ;
}

static void	key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)window;
	(void)scancode;
	(void)action;
	(void)mods;
	printf("Key %d pressed\n", key);
	return ;
}

static void	window_close_callback(GLFWwindow *window)
{
	(void)window;
	printf("Window closed\n");
	return ;
}

static void	window_frame_buffer_size_callback(GLFWwindow *window, int w, int h)
{
	t_ftsglRenderer	*renderer;

	(void)window;
	if (w == 0 || h == 0)
		return ;
	renderer = glfwGetWindowUserPointer(window);
	renderer->window->width = w;
	renderer->window->height = h;
	glViewport(0, 0, w, h);
	return ;
}

t_ftsglWindow	*ftsglWindowCreate(int width, int height, char *title)
{
	t_ftsglWindow	*window;

	glfwSetErrorCallback(error_callback);

	if (GLFW_FALSE == glfwInit())
		return (NULL);

	window = malloc(sizeof(t_ftsglWindow));
	if (NULL == window)
	{
		glfwTerminate();
		return (NULL);
	}
	window->base_width = width;
	window->base_height = height;
	window->width = width;
	window->height = height;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	window->win = glfwCreateWindow(width, height, title, NULL, NULL);
	if (NULL == window->win)
	{
		ftsglWindowDestroy(window);
		return (NULL);
	}
	
	int	maj = glfwGetWindowAttrib(window->win, GLFW_CONTEXT_VERSION_MAJOR);
	int	min = glfwGetWindowAttrib(window->win, GLFW_CONTEXT_VERSION_MINOR);
	printf("OpenGl version: %d.%d\n", maj, min);

	glfwSetKeyCallback(window->win, key_callback);
	glfwSetFramebufferSizeCallback(window->win, window_frame_buffer_size_callback);
	glfwSetWindowCloseCallback(window->win, window_close_callback);
	glfwMakeContextCurrent(window->win);
	glfwSwapInterval(0);

	glewExperimental = GL_TRUE;
	GLenum	glewStatus = glewInit();
	if (GLEW_OK != glewStatus && GLEW_ERROR_NO_GLX_DISPLAY != glewStatus)
	{
		printf("Error: %s\n", glewGetErrorString(glewStatus));
		ftsglWindowDestroy(window);
		return (NULL);
	}

	window->vao = ftsglVaoGen();
	ftsglVaoBind(&window->vao);
	return (window);
}

void	ftsglWindowDestroy(t_ftsglWindow *window)
{
	if (NULL == window)
		return ;
	ftsglVaoDestroy(&window->vao);
	glfwDestroyWindow(window->win);
	glfwTerminate();
	free(window);
	return ;
}
