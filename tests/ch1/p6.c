#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	a;
	t_tuple	b;
	t_tuple	res;

	a = tuple(3, -2, 5, 1);
	b = tuple(-2, 3, 1, 0);
	res = add(a, b);
	printf("-------------------\n");
	printf("Adding two tuples\n");
	printf("a1 + a2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = point_tp(3, 2, 1);
	b = point_tp(5, 6, 7);
	res = subtract(a, b);
	printf("-------------------\n");
	printf("Subtracting two points\n");
	printf("p1 - p2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = point_tp(3, 2, 1);
	b = vector_tp(5, 6, 7);
	res = subtract(a, b);
	printf("-------------------\n");
	printf("Subtracting a vector from a point\n");
	printf("p - v x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
}
