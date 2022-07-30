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

	p1 = point(5, -3, 2);
	p2 = point(-3, 4, 5);
	tp1 = point_tp(p1);
	tp2 = point_tp(p2);
	transform = translation(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("-------------------\n");
	printf("Multiplying by a translation matrix\n");
	printf("transform * p = point(%lf, %lf, %lf)\n", res.x, res.y, res.z);
	transform = translation(tp1);
	inv = inverse(transform, 4);
	res = matrix_multi_tp(inv, tp2);
	printf("-------------------\n");
	printf("Multiplying by the inverse of a translation matrix\n");
	printf("inv * p = point(%lf, %lf, %lf)\n", res.x, res.y, res.z);
	v1 = vector(5, -3, 2);
	v2 = vector(-3, 4, 5);
	tp1 = vector_tp(v1);
	transform = translation(tp1);
	tp2 = vector_tp(v2);
	res = matrix_multi_tp(transform, tp2);
	printf("-------------------\n");
	printf("Translation does not affect vectors\n");
	printf("transform * v = v(%lf, %lf, %lf)\n", res.x, res.y, res.z);
}