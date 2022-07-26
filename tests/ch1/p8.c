#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	a;
	t_tuple	res;

	a = tuple(1, -2, 3, -4);
	res = multiply(a, 3.5);
	printf("-------------------\n");
	printf("Multiplying a tuple by a scalar\n");
	printf("v1 - v2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = tuple(1, -2, 3, -4);
	res = multiply(a, 0.5);
	printf("-------------------\n");
	printf("Multiplying a tuple by a fraction\n");
	printf("v1 - v2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
	a = tuple(1, -2, 3, -4);
	res = divide(a, 2);
	printf("-------------------\n");
	printf("Dividing a tuple by a scalar\n");
	printf("v1 - v2 x:%lf, y:%lf, z:%lf, w:%lf\n",
		res.x, res.y, res.z, res.w);
}
