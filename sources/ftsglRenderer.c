#include "ftsglRenderer.h"

t_ftsglRenderer	*ftsglRendererCreate(t_ftsglWindow *window)
{
	GLsizeiptr		vertices_size;
	GLsizeiptr		elements_size;
	t_ftsglRenderer	*renderer;

	if (NULL == window)
		return (NULL);
	renderer = malloc(sizeof(t_ftsglRenderer));
	if (NULL == renderer)
		return (NULL);
	renderer->vao = ftsglVaoGen();
	ftsglVaoBind(&renderer->vao);
	renderer->window = window;
	vertices_size = window->base_width * window->base_height * sizeof(t_ftsglQuad);
	elements_size = window->base_width * window->base_height * 6 * sizeof(GLuint);
	renderer->vertexBuffer = ftsglBufferObjectGen(GL_ARRAY_BUFFER, vertices_size);
	renderer->elementBuffer = ftsglBufferObjectGen(GL_ELEMENT_ARRAY_BUFFER, elements_size);

	const GLfloat	qw = 2.0f / (GLfloat)window->base_width;
	const GLfloat	qh = 2.0f / (GLfloat)window->base_height;
	for (GLint y = 0; y < window->base_height; ++y)
	{
		for (GLint x = 0; x < window->base_width; ++x)
		{
			const GLuint		index = y * window->base_width + x;
			const GLfloat		qx = x / (GLfloat)window->base_width * 2.0f - 1;
			const GLfloat		qy = y / (GLfloat)window->base_height * 2.0f - 1;
			const t_ftsglQuad	data = ftsglQuad(
				ftsglVec2(qx, qy),
				ftsglVec2(qx + qw, qy + qh),
				ftsglVec4(0, 0, 0, 1.0f)
			);
			ftsglBufferObjectDataAdd(&renderer->vertexBuffer, sizeof(data), &data);

			const GLuint	elements[] = {
				(index * 4)+0, (index * 4)+1, (index * 4)+2,
				(index * 4)+1, (index * 4)+2, (index * 4)+3,
			};
			ftsglBufferObjectDataAdd(&renderer->elementBuffer, sizeof(elements), elements);
		}
	}

	ftsglBufferObjectSync(&renderer->vertexBuffer);
	ftsglBufferObjectSync(&renderer->elementBuffer);

	t_ftsglShader			*shaders[] = {
		ftsglShaderLoad("shaders/vertex_shader.glsl", GL_VERTEX_SHADER),
		ftsglShaderLoad("shaders/fragment_shader.glsl", GL_FRAGMENT_SHADER)
	};
	renderer->program = ftsglProgramCreate(2, shaders, 0, "outColor");
	ftsglProgramAttributeAdd(renderer->program, "position", GL_FLOAT, 2, sizeof(GLfloat) * 6, 0);
	ftsglProgramAttributeAdd(renderer->program, "in_color", GL_FLOAT, 4, sizeof(GLfloat) * 6, (void *)(2 * sizeof(GLfloat)));
	return (renderer);
}

t_ftsglRenderer	*ftsglRendererPresent(t_ftsglRenderer *renderer)
{
	if (NULL == renderer)
		return (NULL);
	ftsglProgramUse(renderer->program);
	glDrawElements(GL_TRIANGLES, (renderer->window->base_width * renderer->window->base_height) * 6, GL_UNSIGNED_INT, 0);
	glfwSwapBuffers(renderer->window->win);
	return (renderer);
}

t_ftsglRenderer	*ftsglRendererSetPixelColor(t_ftsglRenderer *renderer, GLint x, GLint y, t_ftsglVec3 col)
{
	if (NULL == renderer)
		return (NULL);
	if (x < 0 || y < 0 || x >= renderer->window->base_width || y >= renderer->window->base_height)
		return (renderer);
	
	const GLint			ry = renderer->window->base_height - y - 1;
	const GLfloat		qw = 2.0f / (GLfloat)renderer->window->base_width;
	const GLfloat		qh = 2.0f / (GLfloat)renderer->window->base_height;
	const GLfloat		qx = x / (GLfloat)renderer->window->base_width * 2.0f - 1;
	const GLfloat		qy = ry / (GLfloat)renderer->window->base_height * 2.0f - 1;
	const t_ftsglQuad	quad = ftsglQuad(
		ftsglVec2(qx, qy),
		ftsglVec2(qx + qw, qy + qh),
		ftsglVec4(col.x, col.y, col.z, 1.0f)
	);
	ftsglBufferObjectDataUpdate(&renderer->vertexBuffer, (ry * renderer->window->base_width + x) * sizeof(quad), sizeof(quad), &quad);
	return (renderer);
}

t_ftsglRenderer	*ftsglRendererClear(t_ftsglRenderer *renderer, t_ftsglVec3 col)
{
	if (NULL == renderer)
		return (NULL);
	const GLfloat	qw = 2.0f / (GLfloat)renderer->window->base_width;
	const GLfloat	qh = 2.0f / (GLfloat)renderer->window->base_height;
	for (GLint y = 0; y < renderer->window->base_height; ++y)
	{
		for (GLint x = 0; x < renderer->window->base_width; ++x)
		{
			const GLfloat		qx = x / (GLfloat)renderer->window->base_width * 2.0f - 1;
			const GLfloat		qy = y / (GLfloat)renderer->window->base_height * 2.0f - 1;
			const t_ftsglQuad	quad = ftsglQuad(
				ftsglVec2(qx, qy),
				ftsglVec2(qx + qw, qy + qh),
				ftsglVec4(col.x, col.y, col.z, 1.0f)
			);
			ftsglBufferObjectDataUpdate(&renderer->vertexBuffer, (y * renderer->window->base_width + x) * sizeof(quad), sizeof(quad), &quad);
		}
	}
	return (renderer);
}

void	ftsglRendererDestroy(t_ftsglRenderer *renderer)
{
	if (NULL == renderer)
		return ;
	ftsglProgramDestroy(renderer->program);
	ftsglBufferObjectDestroy(&renderer->elementBuffer);
	ftsglBufferObjectDestroy(&renderer->vertexBuffer);
	ftsglVaoDestroy(&renderer->vao);
	free(renderer);
	return ;
}
