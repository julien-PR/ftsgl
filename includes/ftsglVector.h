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

#endif
