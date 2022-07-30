#include "../includes/minirt.h"

t_tuple	add(t_tuple a, t_tuple b)
{
	t_tuple	tp;

	tp.x = (a.x + b.x);
	tp.y = (a.y + b.y);
	tp.z = (a.z + b.z);
	tp.w = (a.w + b.w);
	return (tp);
}

t_vector	negate_vector(t_vector vec)
{
	t_vector	ret;

	ret = vector(0, 0, 0);
	if (vec.x)
		ret.x = vec.x * -1;
	if (vec.y)
		ret.y = vec.y * -1;
	if (vec.z)
		ret.z = vec.z * -1;
	return (ret);
}

t_tuple	negate(t_tuple tp)
{
	t_tuple	ret;

	ret = tuple(0, 0, 0, 0);
	if (tp.x != 0.0)
		ret.x = tp.x * -1;
	if (tp.y != 0.0)
		ret.y = tp.y * -1;
	if (tp.z != 0.0)
		ret.z = tp.z * -1;
	if (tp.w != 0.0)
		ret.w = tp.w * -1;
	return (ret);
}

t_tuple	multiply(t_tuple tp, float num)
{
	t_tuple	ret;

	ret.x = tp.x * num;
	ret.y = tp.y * num;
	ret.z = tp.z * num;
	ret.w = tp.w * num;
	return (ret);
}

t_tuple	divide(t_tuple tp, float num)
{
	t_tuple	ret;

	ret.x = tp.x / num;
	ret.y = tp.y / num;
	ret.z = tp.z / num;
	ret.w = tp.w / num;
	return (ret);
}
