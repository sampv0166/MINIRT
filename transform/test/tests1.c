#include "../../includes/minirt.h"

void	test1(void)
{
	double	**transform;
	t_tuple	*res;
	t_point	*point;
	t_tuple	*tp1;
	t_tuple	*tp2;
	t_point	*p;

	point = malloc(sizeof(t_point));
	p = malloc(sizeof(t_point));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	point->x = 5;
	point->y = -3;
	point->z = 2;
	p->x = -3;
	p->y = 4;
	p->z = 5;
	tp1 = points(point);
	tp2 = points(p);
	transform = translation(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

void	test2(void)
{
	double	**transform;
	double	**inv;
	t_tuple	*res;
	t_point	*point;
	t_tuple	*tp1;
	t_tuple	*tp2;
	t_point	*p;

	point = malloc(sizeof(t_point));
	p = malloc(sizeof(t_point));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	point->x = 5;
	point->y = -3;
	point->z = 2;
	p->x = -3;
	p->y = 4;
	p->z = 5;
	tp1 = points(point);
	transform = translation(tp1);
	inv = inverse(transform, 4);
	tp2 = points(p);
	res = matrix_multi_tp(inv, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

void	test3(void)
{
	double		**transform;
	t_tuple		*res;
	t_vector	*vec;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_vector	*v;

	vec = malloc(sizeof(t_vector));
	v = malloc(sizeof(t_vector));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	vec->x = 5;
	vec->y = -3;
	vec->z = 2;
	v->x = -3;
	v->y = 4;
	v->z = 5;
	tp1 = vectors(vec);
	transform = translation(tp1);
	tp2 = vectors(v);
	res = matrix_multi_tp(transform, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

void	test4(void)
{
	double	**transform;
	t_tuple	*res;
	t_point	*point;
	t_tuple	*tp1;
	t_tuple	*tp2;
	t_point	*p;

	point = malloc(sizeof(t_point));
	p = malloc(sizeof(t_point));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	point->x = 2;
	point->y = 3;
	point->z = 4;
	p->x = -4;
	p->y = 6;
	p->z = 8;
	tp1 = points(point);
	tp2 = points(p);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);

}

void	test5(void)
{
	double		**transform;
	t_tuple		*res;
	t_vector	*vec;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_vector	*v;

	vec = malloc(sizeof(t_vector));
	v = malloc(sizeof(t_vector));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	vec->x = 2;
	vec->y = 3;
	vec->z = 4;
	v->x = -4;
	v->y = 6;
	v->z = 8;
	tp1 = vectors(vec);
	tp2 = vectors(v);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

void	test6(void)
{
	double		**transform;
	double		**inv;
	t_tuple		*res;
	t_vector	*vec;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_vector	*v;

	vec = malloc(sizeof(t_vector));
	v = malloc(sizeof(t_vector));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	vec->x = 2;
	vec->y = 3;
	vec->z = 4;
	v->x = -4;
	v->y = 6;
	v->z = 8;
	tp1 = vectors(vec);
	tp2 = vectors(v);
	transform = scaling(tp1);
	print_matrix(transform, 4);
	inv = inverse(transform, 4);
	print_matrix(inv, 4);
	res = matrix_multi_tp(inv, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);
}

void	test7(void)
{
	double	**transform;
	t_tuple	*res;
	t_point	*point;
	t_tuple	*tp1;
	t_tuple	*tp2;
	t_point	*p;

	point = malloc(sizeof(t_point));
	p = malloc(sizeof(t_point));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	point->x = -1;
	point->y = 1;
	point->z = 1;
	p->x = 2;
	p->y = 3;
	p->z = 4;
	tp1 = points(point);
	tp2 = points(p);
	transform = scaling(tp1);
	res = matrix_multi_tp(transform, tp2);
	printf("x: %lf, y: %lf, z: %lf\n", res->x, res->y, res->z);

}

int	main(void)
{
	test7();
	return (1);
}