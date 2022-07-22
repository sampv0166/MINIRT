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
	t_sphere	*sp1;
	// t_sphere	*sp2;
	t_intersect	*xs;

	ray = malloc(sizeof(t_ray));
	p = malloc(sizeof(t_point));
	v = malloc(sizeof(t_vector));
	sp1 = malloc(sizeof(t_sphere));
	// sp2 = malloc(sizeof(t_sphere));
	p->x = 0;
	p->y = 0;
	p->z = -5;
	v->x = 0;
	v->y = 0;
	v->z = 1;
	ray = create_ray(p, v);
	sp1 = sphere();
	// sp2 = sphere();
	printf("sphere id: %d; center x: %lf, y: %lf, z: %lf; dia: %lf;\n",
		sp1->id, sp1->sp_center.x, sp1->sp_center.y, sp1->sp_center.z,
		sp1->diameter);
	// printf("sphere id: %d; center x: %lf, y: %lf, z: %lf; dia: %lf;\n",
	// 	sp2->id, sp2->sp_center.x, sp2->sp_center.y, sp2->sp_center.z,
	// 	sp2->diameter);
	xs = intersect(sp1, ray);
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs->count, xs->value[0], xs->value[1]);
}

int	main(void)
{
	test3();
	return (0);
}