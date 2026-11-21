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

t_ftsglVec4f	ftsglColorMix4f(const t_ftsglVec4f a, const t_ftsglVec4f b)
{
	t_ftsglVec4f	col = {
		a.x * a.w + b.x * (1.0f - a.w),
		a.y * a.w + b.y * (1.0f - a.w),
		a.z * a.w + b.z * (1.0f - a.w),
		1.0f
	};

	return (col);
}
