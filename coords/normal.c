#include "../includes/minirt.h"

double	magnitude(t_tuple vec)
{
	double		ret;
	double		sum;
	t_tuple		tmp;

	tmp.x = pow(vec.x, 2);
	tmp.y = pow(vec.y, 2);
	tmp.z = pow(vec.z, 2);
	sum = tmp.x + tmp.y + tmp.z;
	ret = sqrt(sum);
	return (ret);
}

t_tuple	normalize(t_tuple vec)
{
	t_tuple		ret;
	double		mag;

	mag = magnitude(vec);
	ret.x = vec.x / mag;
	ret.y = vec.y / mag;
	ret.z = vec.z / mag;
	return (ret);
}
