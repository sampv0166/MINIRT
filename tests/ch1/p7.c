#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	res;

	a = vector(3, 2, 1);
	b = vector(5, 6, 7);
	res = subtract(a, b);
	printf("-------------------\n");
	printf("Subtracting two vectors\n");
	printf("v1 - v2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = vector(0, 0, 0);
	b = vector(1, -2, 3);
	res = subtract(a, b);
	printf("-------------------\n");
	printf("Subtracting a vector from the zero vector\n");
	printf("zero - v x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = tuple(1, -2, 3, -4);
	res = negate(a);
	printf("-------------------\n");
	printf("Negating a tuple\n");
	printf("-a x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
}
