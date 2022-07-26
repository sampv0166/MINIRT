#include "../includes/minirt.h"

int	double_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

int	tuple_equal(t_tuple a, t_tuple b)
{
	if (double_equal(a.x, b.x) && double_equal(a.y, b.y) 
		&& double_equal (a.z, b.z))
	{
		if (a.w == b.w)
			return (1);
	}
	return (0);
}