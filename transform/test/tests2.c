#include "../../includes/minirt.h"

void	test1(void)
{
	t_tuple	*res1;
	t_tuple	*res2;
	t_point	*p;
	t_tuple	*tp;
	double	**hquat;
	double	**fquat;

	p = malloc(sizeof(t_point));
	p->x = 0;
	p->y = 1;
	p->z = 0;
	tp = points(p);
	hquat = rotation_x(PI / 4);
	fquat = rotation_x(PI / 2);
	res1 = matrix_multi_tp(hquat, tp);
	res2 = matrix_multi_tp(fquat, tp);
	printf("x: %lf, y: %lf, z: %lf\n", res1->x, res1->y, res1->z);
	printf("x: %lf, y: %lf, z: %lf\n", res2->x, res2->y, res2->z);
}

void	test2(void)
{
	t_tuple	*res;
	t_point	*p;
	t_tuple	*tp;
	double	**hquat;
	double	**inv;

	p = malloc(sizeof(t_point));
	p->x = 0;
	p->y = 1;
	p->z = 0;
	tp = points(p);
	hquat = rotation_x(PI / 4);
	inv = inverse(hquat, 4);
	res = matrix_multi_tp(hquat, tp);
	printf("PI: %lf\n", PI);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

int	main(void)
{
	test2();
	return (0);
}