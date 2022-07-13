#include "../includes/minirt.h"

int	equal(double a, double b)
{
	if (abs(a -b) < EPSILON)
		return (1);
	else
		return (0);
}

int	tuple_equal(t_tuple a, t_tuple b)
{
	if (equal(a.x, b.x) && equal(a.y, b.y) && equal (a.z, b.z))
	{
		if (a.w == b.w)
			return (1);
	}
	else
		return (0);
}