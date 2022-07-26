#include "../../includes/minirt.h"


int	main(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	res;

	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	res = cross(a, b);
	printf("-------------------\n");
	printf("The cross product of two vectors\n");
	printf("cross(a, b) x:%lf, y:%lf, z:%lf\n",
		res.x, res.y, res.z);
	res = cross(b, a);
	printf("-------------------\n");
	printf("The cross product of two vectors\n");
	printf("cross(b, a) x:%lf, y:%lf, z:%lf\n",
		res.x, res.y, res.z);
	return (0);
}