#include "../includes/minirt.h"

t_ray	*create_ray(t_point *p, t_vector *v)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->origin = p;
	ray->direction = v;
	return (ray);
}

t_tuple	*position(t_ray *r, float num)
{
	t_tuple *multi;
	t_tuple	*vec;
	t_tuple	*point;

	vec = vectors(r->direction);
	multi = scalar_mlp(vec, num);
	point = points(r->origin);
	return (add_tuple(point, multi));
}

t_sphere	*sphere(void)
{
	t_sphere	*sp;
	t_point		center;
	static int	id;

	sp = malloc(sizeof(t_sphere));
	if (!id)
		id = 0;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	sp->sp_center = center;
	sp->diameter = 2.0;
	sp->id = id++;
	return (sp);
}

t_intersect	*intersect(t_sphere *s, t_ray *r)
{
	t_intersect	*inter;
	t_point		*sphere_to_ray;
	t_tuple		*tp1;
	t_tuple		*tp2;
	double		a;
	double		b;
	double		c;
	double		d;

	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	inter = malloc(sizeof(t_intersect));
	sphere_to_ray = subtract_vector(&s->sp_center, r->direction);
	printf("x: %lf, y: %lf, z: %lf\n", 
		sphere_to_ray->x, sphere_to_ray->y,
		sphere_to_ray->z);
	tp1 = vectors(r->direction);
	a = dot_product(tp1, tp1);
	tp2 = points(sphere_to_ray);
	b = 2 * dot_product(tp1, tp2);
	c = dot_product(tp2, tp2) - 1;
	printf("a: %lf, b: %lf, c: %lf\n", a, b, c);
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
	{
		inter->count = 0;
		inter->value[0] = 0;
		inter->value[1] = 0;
		return (inter);
	}
	inter->count = 2;
	inter->value[0] = (-b - sqrt(d)) / (2 * a);
	inter->value[1] = (-b + sqrt(d)) / (2 * a);
	return (inter);
}