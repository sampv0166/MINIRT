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

t_tuple	vector(double x, double y, double z)
{
	t_tuple	tp;

	tp.x = x;
	tp.y = y;
	tp.z = z;
	tp.w = 0.0;
	return (tp);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	tp;

	tp.x = x;
	tp.y = y;
	tp.z = z;
	tp.w = 1.0;
	return (tp);
}

int	check_type(t_tuple *tp)
{
	if (tp->w == 1.0)
		return (1);
	return (0);
}
