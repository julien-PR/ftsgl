#ifndef FTSGL_VECTOR_H
# define FTSGL_VECTOR_H

typedef struct s_ftsglVector2D
{
	double	x;
	double	y;
}	t_ftsglVec2;

typedef struct s_ftsglVector3D
{
	double	x;
	double	y;
	double	z;
}	t_ftsglVec3;

typedef struct s_ftsglVector4D
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_ftsglVec4;

t_ftsglVec2	ftsglVec2(double x, double y);

t_ftsglVec3	ftsglVec3(double x, double y, double z);

t_ftsglVec4	ftsglVec4(double x, double y, double z, double w);

typedef struct s_ftsglVector2Df
{
	float	x;
	float	y;
}	t_ftsglVec2f;

typedef struct s_ftsglVector3Df
{
	float	x;
	float	y;
	float	z;
}	t_ftsglVec3f;

typedef struct s_ftsglVector4Df
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_ftsglVec4f;

t_ftsglVec2f	ftsglVec2f(float x, float y);

t_ftsglVec3f	ftsglVec3f(float x, float y, float z);

t_ftsglVec4f	ftsglVec4f(float x, float y, float z, float w);

typedef struct s_ftsglVector2Di
{
	int	x;
	int	y;
}	t_ftsglVec2i;

typedef struct s_ftsglVector3Di
{
	int	x;
	int	y;
	int	z;
}	t_ftsglVec3i;

typedef struct s_ftsglVector4Di
{
	int	x;
	int	y;
	int	z;
	int	w;
}	t_ftsglVec4i;

t_ftsglVec2i	ftsglVec2i(int x, int y);

t_ftsglVec3i	ftsglVec3i(int x, int y, int z);

t_ftsglVec4i	ftsglVec4i(int x, int y, int z, int w);

#endif
