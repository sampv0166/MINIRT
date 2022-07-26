#include "../includes/minirt.h"

double	dot(t_tuple a, t_tuple b)
{
	double	ret;

	ret = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	return (ret);
}

t_vector	cross_product(t_vector vec1, t_vector vec2)
{
	t_vector	ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (ret);
}

t_tuple	cross(t_tuple vec1, t_tuple vec2)
{
	t_tuple	ret;

	ret.x = vec1.y * vec2.z - vec1.z * vec2.y;
	ret.y = vec1.z * vec2.x - vec1.x * vec2.z;
	ret.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (ret);
}