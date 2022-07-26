#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	res;
	double	mag;
	double	d;

	a = vector(4, 0, 0);
	res = normalize(a);
	printf("-------------------\n");
	printf("Normalizing vector(4, 0, 0) gives vector(1, 0, 0)\n");
	printf("x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = vector(1, 2, 3);
	res = normalize(a);
	printf("-------------------\n");
	printf("Normalizing vector(1, 2, 3)\n");
	printf("x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	mag = magnitude(res);
	printf("-------------------\n");
	printf("The magnitude of a normalized vector\n");
	printf("magnitude :%lf\n", mag);
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	d = dot(a, b);
	printf("-------------------\n");
	printf("The dot product of two tuples\n");
	printf("dot(a, b) = %lf\n", d);
}
