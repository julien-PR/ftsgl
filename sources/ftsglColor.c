#include "ftsglColor.h"

t_ftsglVec3f	ftsglColorMix(const t_ftsglVec3f a, const t_ftsglVec3f b, float alpha)
{
	t_ftsglVec3f	col = {
		a.x * alpha + b.x * (1 - alpha),
		a.y * alpha + b.y * (1 - alpha),
		a.x * alpha + b.z * (1 - alpha),
	};

	return (col);
}
