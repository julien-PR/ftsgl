#include "ftsglVector.h"

t_ftsglVec2	ftsglVec2(double x, double y)
{
	return ((t_ftsglVec2){x, y});
}

t_ftsglVec3	ftsglVec3(double x, double y, double z)
{
	return ((t_ftsglVec3){x, y, z});
}

t_ftsglVec4	ftsglVec4(double x, double y, double z, double w)
{
	return ((t_ftsglVec4){x, y, z, w});
}

t_ftsglVec2f	ftsglVec2f(float x, float y)
{
	return ((t_ftsglVec2f){x, y});
}

t_ftsglVec3f	ftsglVec3f(float x, float y, float z)
{
	return ((t_ftsglVec3f){x, y, z});
}

t_ftsglVec4f	ftsglVec4f(float x, float y, float z, float w)
{
	return ((t_ftsglVec4f){x, y, z, w});
}

t_ftsglVec2i	ftsglVec2i(int x, int y)
{
	return ((t_ftsglVec2i){x, y});
}

t_ftsglVec3i	ftsglVec3i(int x, int y, int z)
{
	return ((t_ftsglVec3i){x, y, z});
}

t_ftsglVec4i	ftsglVec4i(int x, int y, int z, int w)
{
	return ((t_ftsglVec4i){x, y, z, w});
}
