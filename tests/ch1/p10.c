#include "../../includes/minirt.h"

int	main(void)
{
	t_vector	a;
	t_tuple		b;
	t_tuple		c;
	t_vector	res;
	double		mag;
	double		d;

	a = vector(4, 0, 0);
	res = normalize(a);
	printf("-------------------\n");
	printf("Normalizing vector(4, 0, 0) gives vector(1, 0, 0)\n");
	printf("x:%lf, y:%lf, z:%lf\n",
		res.x, res.y, res.z);
	a = vector(1, 2, 3);
	res = normalize(a);
	printf("-------------------\n");
	printf("Normalizing vector(1, 2, 3)\n");
	printf("x:%lf, y:%lf, z:%lf\n",
		res.x, res.y, res.z);
	mag = magnitude(res);
	printf("-------------------\n");
	printf("The magnitude of a normalized vector\n");
	printf("magnitude :%lf\n", mag);
	b = vector_tp(1, 2, 3);
	c = vector_tp(2, 3, 4);
	d = dot(b, c);
	printf("-------------------\n");
	printf("The dot product of two tuples\n");
	printf("dot(a, b) = %lf\n", d);
}
