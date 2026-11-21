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
