#include "../../includes/minirt.h"

int	main(void)
{

	double		**transform;
	double		**inv;
	t_tuple		res;
	t_tuple		tp1;
	t_tuple		tp2;
	t_point		p1;
	t_point		p2;
	t_vector	v1;
	t_vector	v2;

	p1 = point(2, 3, 4);
	p2 = point(-4, 6, 8);
	tp1 = point_tp(p1);
	tp2 = point_tp(p2);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("-------------------\n");
	printf("A scaling matrix applied to a point\n");
	printf("transform * p = point(%lf, %lf, %lf)\n", res.x, res.y, res.z);
	v1 = vector(2, 3, 4);
	v2 = vector(-4, 6, 8);
	tp1 = vector_tp(v1);
	tp2 = vector_tp(v2);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("-------------------\n");
	printf("A scaling matrix applied to a point\n");
	printf("transform * v = vector(%lf, %lf, %lf)\n", res.x, res.y, res.z);
	inv = inverse(transform, 4);
	res = matrix_multi_tp(inv, tp2);
	printf("-------------------\n");
	printf("Multiplying by the inverse of a scaling matrix\n");
	printf("inv * v = vector(%lf, %lf, %lf)\n", res.x, res.y, res.z);
}