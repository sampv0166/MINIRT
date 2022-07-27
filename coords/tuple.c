#include "../includes/minirt.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	tp;

	tp.x = x;
	tp.y = y;
	tp.z = z;
	tp.w = w;
	return (tp);
}

t_vector	vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_point	point(double x, double y, double z)
{
	t_point	pt;

	pt.x = x;
	pt.y = y;
	pt.z = z;
	return (pt);
}

t_tuple	vector_tp(t_vector vec)
{
	t_tuple	tp;
	double	w;

	w = 0.0;
	tp = tuple(vec.x, vec.y, vec.z, w);
	return (tp);
}

t_tuple	point_tp(t_point p)
{
	t_tuple	tp;
	double	w;

	w = 1.0;
	tp = tuple(p.x, p.y, p.z, w);
	return (tp);
}
