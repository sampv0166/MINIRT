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

void	test3(void)
{
	t_tuple	*res1;
	t_tuple	*res2;
	t_point	*p;
	t_tuple	*tp;
	double	**hquat;
	double	**fquat;

	p = malloc(sizeof(t_point));
	p->x = 0;
	p->y = 0;
	p->z = 1;
	tp = points(p);
	hquat = rotation_y(PI / 4);
	fquat = rotation_y(PI / 2);
	res1 = matrix_multi_tp(hquat, tp);
	res2 = matrix_multi_tp(fquat, tp);
	printf("x: %lf, y: %lf, z: %lf\n", res1->x, res1->y, res1->z);
	printf("x: %lf, y: %lf, z: %lf\n", res2->x, res2->y, res2->z);
}

void	test4(void)
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
	hquat = rotation_z(PI / 4);
	fquat = rotation_z(PI / 2);
	res1 = matrix_multi_tp(hquat, tp);
	res2 = matrix_multi_tp(fquat, tp);
	printf("x: %lf, y: %lf, z: %lf\n", res1->x, res1->y, res1->z);
	printf("x: %lf, y: %lf, z: %lf\n", res2->x, res2->y, res2->z);
}

void	test5(void)
{
	t_tuple	*res;
	t_point	*p;
	t_tuple	*tp;
	double	*coord;
	double	**mat;

	p = malloc(sizeof(t_point));
	coord = malloc(sizeof(double) *  6);
	p->x = 2;
	p->y = 3;
	p->z = 4;
	tp = points(p);
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	coord[3] = 0;
	coord[4] = 0;
	coord[5] = 1;
	res = shearing(tp, coord);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

//chaining transformations
void	test6(void)
{
	t_point	*p;
	t_tuple	*tp;
	t_tuple	*tps;
	t_tuple	*tpt;
	t_tuple	*r1;
	t_tuple	*r2;
	t_tuple	*r3;
	double	**A;
	double	**B;
	double	**C;

	p = malloc(sizeof(t_point));
	tps = malloc(sizeof(t_tuple));
	tpt = malloc(sizeof(t_tuple));
	p->x = 1;
	p->y = 0;
	p->z = 1;
	tp = points(p);
	A = rotation_x(PI / 2);
	r1 = matrix_multi_tp(A, tp);
	tps->x = 5;
	tps->y = 5;
	tps->z = 5;
	tps->w = 1;
	tpt->x = 10;
	tpt->y = 5;
	tpt->z = 7;
	tpt->w = 1;
	B = scaling(tps);
	r2 = matrix_multi_tp(B, r1);
	C = translation(tpt);
	r3 = matrix_multi_tp(C, r2);
	printf("x: %lf, y: %lf, z: %lf\n", r1->x, r1->y, r1->z);
	printf("x: %lf, y: %lf, z: %lf\n", r2->x, r2->y, r2->z);
	printf("x: %lf, y: %lf, z: %lf\n", r3->x, r3->y, r3->z);
}

void	test7(void)
{
	t_point	*p;
	t_tuple	*tp;
	t_tuple	*tps;
	t_tuple	*tpt;
	t_tuple	*r;
	double	**A;
	double	**B;
	double	**C;
	double	**res;

	p = malloc(sizeof(t_point));
	tps = malloc(sizeof(t_tuple));
	tpt = malloc(sizeof(t_tuple));
	p->x = 1;
	p->y = 0;
	p->z = 1;
	tp = points(p);
	A = rotation_x(PI / 2);
	tps->x = 5;
	tps->y = 5;
	tps->z = 5;
	tps->w = 1;
	tpt->x = 10;
	tpt->y = 5;
	tpt->z = 7;
	tpt->w = 1;
	B = scaling(tps);
	C = translation(tpt);
	res = matrix_multi(C, matrix_multi(B, A));
	r = matrix_multi_tp(res, tp);
	printf("x: %lf, y: %lf, z: %lf\n", r->x, r->y, r->z);
}

int	main(void)
{
	test7();
	return (0);
}