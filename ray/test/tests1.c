#include "../../includes/minirt.h"

void	test1(void)
{
	t_ray		*ray;
	t_point		*p;
	t_vector	*v;

	ray = malloc(sizeof(t_ray));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	p->x = 1;
	p->y = 2;
	p->z = 3;
	v->x = 4;
	v->y = 5;
	v->z = 6;
	ray = create_ray(p, v);
	printf("origin: %lf, %lf, %lf; direction: %lf, %lf, %lf\n",
		ray->origin->x, ray->origin->y, ray->origin->z,
		ray->direction->x, ray->direction->y, ray->direction->z);
}

void	test2(void)
{
	t_ray		*ray;
	t_point		*p;
	t_vector	*v;
	t_tuple		*pos;

	ray = malloc(sizeof(t_ray));
	pos = malloc(sizeof(t_tuple));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	p->x = 2;
	p->y = 3;
	p->z = 4;
	v->x = 1;
	v->y = 0;
	v->z = 0;
	ray = create_ray(p, v);
	pos = position(ray, 2.5);
	printf("x: %lf, y: %lf, z: %lf, w: %lf\n", pos->x, pos->y, pos->z, pos->w);
}

void	test3(void)
{
	t_ray		*ray;
	t_point		*p;
	t_vector	*v;
	t_sphere	*sp;
	t_intersect	*xs;

	ray = malloc(sizeof(t_ray));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	sp = malloc(sizeof(t_sphere));
	p->x = 0;
	p->y = 0;
	p->z = 0;
	v->x = 0;
	v->y = 0;
	v->z = 1;
	ray = create_ray(p, v);
	sp = sphere();
	printf("sphere id: %d; center x: %lf, y: %lf, z: %lf; rad: %lf;\n",
		sp->id, sp->sp_center.x, sp->sp_center.y, sp->sp_center.z,
		sp->radius);
	xs = intersect(sp, ray);
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs->count, xs->value[0], xs->value[1]);
}

void	test4(void)
{
	t_sphere		*s;
	t_intersection	*i;

	s = malloc(sizeof(t_sphere));
	s = sphere();
	i = intersection(3.5, s);
	printf("t value: %lf object id: %d\n", i->t, i->object->id);
}

void	test5(void)
{
	t_sphere		*s;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersection	**xs;

	s = malloc(sizeof(t_sphere));
	s = sphere();
	i1 = intersection(1, s);
	i2 = intersection(2, s);
	xs = intersections2(2, i1, i2);
	printf("t value: %lf object type: %d\n", xs[0]->t, xs[0]->object == s);
	printf("t value: %lf object type: %d\n", xs[1]->t, xs[1]->object == s);
}

void	test6(void)
{
	t_sphere		*s;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersection	*i;
	t_intersection	**xs;

	s = malloc(sizeof(t_sphere));
	s = sphere();
	i1 = intersection(1, s);
	i2 = intersection(2, s);
	xs = intersections(i2, i1);
	i = hit(xs);
	if (i->t)
		printf("t value: %lf\n", i->t);
	else
		printf("nothing");
}

void	test7(void)
{
	t_sphere		*s;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersection	*i3;
	t_intersection	*i4;
	t_intersection	*i;
	t_intersection	**xs;

	s = malloc(sizeof(t_sphere));
	s = sphere();
	i1 = intersection(5, s);
	i2 = intersection(7, s);
	i3 = intersection(-3, s);
	i4 = intersection(2, s);
	xs = intersections2(4, i1, i2, i3, i4);
	i = hit(xs);
	if (i->t)
		printf("t value: %lf\n", i->t);
	else
		printf("nothing");
}

int	main(void)
{
	test7();
	return (0);
}