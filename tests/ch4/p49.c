#include "../../includes/minirt.h"

int	main(void)
{
	t_tuple	res1;
	t_tuple	res2;
	t_point	p;
	t_tuple	tp;
	double	**hquat;
	double	**fquat;
	double	**inv;

	p = point(0, 1, 0);
	tp = point_tp(p);
	hquat = rotation_x(PI / 4);
	inv = inverse(hquat, 4);
	res1 = matrix_multi_tp(hquat, tp);
	printf("-------------------\n");
	printf("The inverse of an x-rotation rotates in the opp direction\n");
	printf("inv * p = point (%lf, %lf, %lf)\n", res1.x, res1.y, res1.z);
	p = point(0, 0, 1);
	tp = point_tp(p);
	hquat = rotation_y(PI / 4);
	fquat = rotation_y(PI / 2);
	res1 = matrix_multi_tp(hquat, tp);
	res2 = matrix_multi_tp(fquat, tp);
	printf("-------------------\n");
	printf("Rotating a point around the y axis\n");
	printf("half quarter * p = point(%lf, %lf, %lf)\n", res1.x, res1.y, res1.z);
	printf("full quarter * p = point(%lf, %lf, %lf)\n", res2.x, res2.y, res2.z);
}