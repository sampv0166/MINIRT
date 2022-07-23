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
	sp->radius = 1.0;
	sp->id = id++;
	sp->transform = identity_matrix();
	return (sp);
}

t_intersect	*intersect(t_sphere *s, t_ray *r)
{
	t_intersect	*inter;
	t_vector	*sphere_to_ray;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_ray		*r2;
	double		a;
	double		b;
	double		c;
	double		d;

	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	inter = malloc(sizeof(t_intersect));
	r2 = transform(r, inverse(s->transform, 4));
	printf("origin: %lf, %lf, %lf\n",
		r2->origin->x, r2->origin->y, r2->origin->z);
	printf("direction: %lf, %lf, %lf\n",
		r2->direction->x, r2->direction->y, r2->direction->z);
	printf("___________________\n");
	sphere_to_ray = subtract_points(r2->origin, &s->sp_center);
	tp1 = vectors(r2->direction);
	a = dot_product(tp1, tp1);
	tp2 = vectors(sphere_to_ray);
	b = 2 * dot_product(tp1, tp2);
	c = dot_product(tp2, tp2) - 1;
	d = pow(b, 2) - 4 * a * c;
	printf("a: %lf, b: %lf, c: %lf, d: %lf\n", a, b, c, d);
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

t_intersection	*intersection(double value, void *object)
{
	t_intersection	*i;

	i = malloc(sizeof(t_intersection));
	i->object = malloc(sizeof(typeof(object)));
	i->t = value;
	i->object = object;
	return (i);
}

t_intersection	**intersections(t_intersection *i1, t_intersection *i2)
{
	t_intersection	**ret;

	ret = malloc(sizeof(t_intersection) * 2);
	ret[0] = i1;
	ret[1] = i2;
	return (ret);
}

t_intersection	**intersections2(int n, ...)
{
	t_intersection	**ret;
	int				i;
	va_list			inters;

	ret = malloc(sizeof(t_intersection) * n);
	i = 0;
	va_start(inters, n);
	while (i < n)
	{
		ret[i] = va_arg(inters, t_intersection *);
		i++;
	}
	va_end(inters);
	return (ret);
}

t_intersection	*hit(t_intersection **xs)
{
	int				i;
	t_intersection	*inter;

	i = 0;
	inter = malloc(sizeof(t_intersection));
	while (xs[i])
	{
		if (xs[i]->t > 0)
			inter = xs[i];
		i++;
	}
	return (inter);
}

t_ray	*transform(t_ray *r, double **m)
{
	t_ray		*ret;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_tuple		*multi1;
	t_tuple		*multi2;
	t_point		*point;
	t_vector	*vec;

	ret = malloc(sizeof(t_ray));
	point = malloc(sizeof(t_point));
	vec = malloc(sizeof(t_vector));
	tp1 = points(r->origin);
	multi1 = matrix_multi_tp(m, tp1);
	tp2 = vectors(r->direction);
	multi2 = matrix_multi_tp(m, tp2);
	point->x = multi1->x;
	point->y = multi1->y;
	point->z = multi1->z;
	vec->x = multi2->x;
	vec->y = multi2->y;
	vec->z = multi2->z;
	ret->origin = point;
	ret->direction = vec;
	return (ret);
}

void	set_transform(t_sphere *s, double **t)
{
	s->transform = t;
}