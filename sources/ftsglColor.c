#include "ftsglColor.h"

t_ftsglVec3f	ftsglColorMix(const t_ftsglVec3f a, const t_ftsglVec3f b, float alpha)
{
	t_ftsglVec3f	col = {
		a.x * alpha + b.x * (1.0f - alpha),
		a.y * alpha + b.y * (1.0f - alpha),
		a.z * alpha + b.z * (1.0f - alpha),
	};

	return (col);
}
