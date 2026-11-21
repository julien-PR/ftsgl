#ifndef FTSGL_COLOR_H
# define FTSGL_COLOR_H

# include "ftsglVector.h"

t_ftsglVec3f	ftsglColorMix(const t_ftsglVec3f a, const t_ftsglVec3f b, float alpha);

t_ftsglVec4f	ftsglColorMix4f(const t_ftsglVec4f a, const t_ftsglVec4f b);

#endif
