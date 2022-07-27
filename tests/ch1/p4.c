#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	a;

	printf("-------------------\n");
	printf("A tuple with w=1.0 is a point\n");
	a = tuple(4.3, -4.2, 3.1, 1.0);
	printf("a x:%lf, y:%lf, z:%lf, w:%lf\n",
		a.x, a.y, a.z, a.w);
	printf("-------------------\n");
	printf("A tuple with w=0 is a vector\n");
	a = tuple(4.3, -4.2, 3.1, 0.0);
	printf("a x:%lf, y:%lf, z:%lf, w:%lf\n",
		a.x, a.y, a.z, a.w);
	printf("-------------------\n");
	printf("point() creates tuple with w=1\n");
	a = point_tp(4, -4, 3);
	printf("a x:%lf, y:%lf, z:%lf, w:%lf\n",
		a.x, a.y, a.z, a.w);
	printf("-------------------\n");
	printf("vector() creates tuple with w=0\n");
	a = vector_tp(4, -4, 3);
	printf("a x:%lf, y:%lf, z:%lf, w:%lf\n",
		a.x, a.y, a.z, a.w);
}
