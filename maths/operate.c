#include "../includes/minirt.h"

t_vector	*negate_vector(t_vector *vec)
{
	t_vector	*ret;

	ret.x = vec.x * -1;
	ret.y = vec.y * -1;
	ret.z = vec.z * -1;
	return (ret);
}

t_tuple	*negate_tuple(t_tuple *tp)
{
	t_tuple	*ret;

	ret.x = tp.x * -1;
	ret.y = tp.y * -1;
	ret.z = tp.z * -1;
	return (ret);
}

t_tuple	*scalar_mlp(t_tuple *tp, float num)
{
	t_tuple	*ret;

	ret.x = tp.x * num;
	ret.y = tp.y * num;
	ret.z = tp.z * num;
	ret.w = tp.w * num;
	return (ret);
}

t_tuple	*scalar_div(t_tuple *tp, float num)
{
	t_tuple	*ret;

	ret.x = tp.x / num;
	ret.y = tp.y / num;
	ret.z = tp.z / num;
	ret.w = tp.w / num;
	return (ret);
}
