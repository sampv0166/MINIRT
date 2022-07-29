#include "../../includes/minirt.h"

int	main(void)
{
	double	**transform;
	t_tuple	res;
	t_tuple	tp1;
	t_tuple	tp2;
	t_point	p1;
	t_point	p2;

	p1 = point(-1, 1, 1);
	p2 = point(2, 3, 4);
	tp1 = point_tp(p1);
	tp2 = point_tp(p2);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("-------------------\n");
	printf("Reflection is scaling by a negative value\n");
	printf("transform * p = point(%lf, %lf, %lf)\n", res.x, res.y, res.z);
}