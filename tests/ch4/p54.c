#include "../../includes/minirt.h"

int	main(void)
{
	t_point	p;
	t_tuple	tp;
	t_tuple	tps;
	t_tuple	tpt;
	t_tuple	r1;
	t_tuple	r2;
	t_tuple	r3;
	t_tuple	r4;
	double	**A;
	double	**B;
	double	**C;
	double	**res;

	p = point(1, 0, 1);
	tp = point_tp(p);
	A = rotation_x(PI / 2);
	r1 = matrix_multi_tp(A, tp);
	tps = tuple(5, 5, 5, 1);
	tpt = tuple(10, 5, 7, 1);
	B = scaling(tps);
	r2 = matrix_multi_tp(B, r1);
	C = translation(tpt);
	r3 = matrix_multi_tp(C, r2);
	printf("-------------------\n");
	printf("Individual transformations\n");
	printf("x: %lf, y: %lf, z: %lf\n", r1.x, r1.y, r1.z);
	printf("x: %lf, y: %lf, z: %lf\n", r2.x, r2.y, r2.z);
	printf("x: %lf, y: %lf, z: %lf\n", r3.x, r3.y, r3.z);
	res = matrix_multi(C, matrix_multi(B, A));
	r4 = matrix_multi_tp(res, tp);
	printf("-------------------\n");
	printf("Chained transformations\n");
	printf("x: %lf, y: %lf, z: %lf\n", r4.x, r4.y, r4.z);
}