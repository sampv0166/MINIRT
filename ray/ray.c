#include "../includes/minirt.h"
#include <stdarg.h>

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
	return (sp);
}

t_intersection *intersection(double i, void *obj)
{
	t_intersection *ret;

	ret = malloc(sizeof(ret));
	ret->t = i;	
	ret->obj = obj;
	return (ret);
}

t_intersection1 *intersections(int n,...)
{
	t_intersection1 *ret;
	int i;
	va_list inters;

	ret = malloc (sizeof(t_intersection1));
	i = 0;
	ret->ins = malloc(sizeof (t_intersection *) * n);
	va_start(inters, n);
	while (i < n)
	{
		ret->ins[i] = va_arg(inters,t_intersection *);
		i++;
	}

	ret->count = n;
	return (ret);
}

t_intersection *hit(t_intersection1 *inter_sects)
{
	int i;
	double min;
	t_intersection *ret;
	ret = NULL;

	i = 0;
	min = __LONG_LONG_MAX__;
	while (i < 4)
	{
		if ((min > inter_sects->ins[i]->t) && (inter_sects->ins[i]->t > 0))
		{
			min = inter_sects->ins[i]->t; 
			ret = inter_sects->ins[i];
		}
		i++;
	}
	return (ret);
}

t_intersection1 *intersect(t_sphere *s, t_ray *r, t_intersect *inter)
{
	t_tuple	sphere_to_ray;
	t_intersection *t1;
	t_intersection *t2;
	t_intersection1 *ret;

	ret = NULL;
	subtract_points_new(r->origin, &s->sp_center, &sphere_to_ray);
	double a;
	double b;
	double c;
	double disc;
	t_tuple tp;

	vector_to_tuple(r->direction, &tp);
	a = dot_product(&tp, &tp);
	b = 2 * dot_product(&tp,&sphere_to_ray);
	c = dot_product(&sphere_to_ray, &sphere_to_ray) - 1;

	disc =  pow(b, 2) - 4 * a * c;
	if (disc < 0)
	{
		inter->count = 0;
		inter->value[0] = 0.0;
		inter->value[1] = 0.0;
		return (ret);
	}
	inter->count = 2;
	inter->value[0] = (-b - sqrt(disc)) / (2 * a);
	inter->value[1] = (-b + sqrt(disc)) / (2 * a);

	t1 = intersection(inter->value[0], s);
	t2 = intersection(inter->value[1], s);
	ret = intersections(2, t1,t2);

	return (ret);
	// int i;
	// i = 0;
	// while (i > inter->count)
	// {
	// t1 = intersection(inter->value[i], s);
	// 	i++
	// }
	
	
	// t_vector		*sphere_to_ray;
	// t_tuple		*tp1;
	// t_tuple		*tp2;
	// double		a;
	// double		b;
	// double		c;
	// double		d;

	// tp1 = malloc(sizeof(t_tuple));
	// tp2 = malloc(sizeof(t_tuple));
	// inter = malloc(sizeof(t_intersect));
	// sphere_to_ray = subtract_points(r->origin, &s->sp_center);
	// printf("x: %lf, y: %lf, z: %lf\n", 
	// 	sphere_to_ray->x, sphere_to_ray->y,
	// 	sphere_to_ray->z);
	// tp1 = vectors(r->direction);
	// a = dot_product(tp1, tp1);
	
	// tp2->x = sphere_to_ray->x;
	// tp2->y = sphere_to_ray->y;
	// tp2->z = sphere_to_ray->z;
	// tp2->w  = 1;

	// b = 2 * dot_product(tp1, tp2);
	// c = dot_product(tp2, tp2) - 1;
	// printf("a: %lf, b: %lf, c: %lf\n", a, b, c);
	// d = pow(b, 2) - 4 * a * c;
	// if (d < 0)
	// {
	// 	inter->count = 0;
	// 	inter->value[0] = 0;
	// 	inter->value[1] = 0;
	// 	return (inter);
	// }
	// inter->count = 2;
	// inter->value[0] = (-b - sqrt(d)) / (2 * a);
	// inter->value[1] = (-b + sqrt(d)) / (2 * a);
}



