#ifndef FTSGL_RENDERER_H
# define FTSGL_RENDERER_H

# include <stdlib.h>
# include "ftsglWindow.h"
# include "ftsglImage.h"
# include "ftsglBufferObject.h"
# include "ftsglShader.h"
# include "ftsglColor.h"

typedef struct s_ftsglRenderer
{
	t_ftsglVao				vao;
	t_ftsglWindow			*window;
	t_ftsglShaderProgram	*program;
	t_ftsglBufferObject		vertexBuffer;
	t_ftsglBufferObject		elementBuffer;
}	t_ftsglRenderer;

t_ftsglRenderer	*ftsglRendererCreate(t_ftsglWindow *window);

t_ftsglRenderer	*ftsglRendererPresent(t_ftsglRenderer *renderer);

t_ftsglRenderer	*ftsglRendererSetPixelColor(t_ftsglRenderer *renderer, GLint x, GLint y, t_ftsglVec3f col);

t_ftsglRenderer	*ftsglRendererClear(t_ftsglRenderer *renderer, t_ftsglVec4f col);

t_ftsglRenderer	*ftsglRendererPutImage(t_ftsglRenderer *renderer, t_ftsglImage *image, int x, int y);

void	ftsglRendererDestroy(t_ftsglRenderer *renderer);

#endif
