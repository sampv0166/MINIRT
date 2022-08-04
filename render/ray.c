#include "../includes/minirt.h"
#include <string.h>
t_ray	ray(t_point p, t_vector v)
{
	t_ray	ray;

	ray.origin = p;
	ray.direction = v;
	return (ray);
}

t_point	position(t_ray r, float num)
{
	t_tuple	multi;
	t_tuple	res;
	t_point	p;

	multi = multiply(vector_tp(r.direction), num);
	res = add(point_tp(r.origin), multi);
	p = point(res.x, res.y, res.z);
	return (p);
}

t_sphere	*sphere(void)
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	t_point		center;
	static int	id;

	if (!id)
		id = 0;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	sp->sp_center = center;
	sp->radius = 4.0;
	sp->id = id++;

	return (sp);
}

t_plane	*plane(void)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	pl->xyz = tuple(0,0,0,0);
	return (pl);
}

t_shape create_shape(int i)
{
	t_shape shape;
	shape.transform = identity_matrix();
	shape.material = material();
	if (i == 1)
	{
		shape.shape = sphere();
	}
	else if (i == 2)
	{
		shape.shape = plane();
	}
	return (shape);
}


t_intersect	local_intersect_sphere(t_ray r2)
{
	t_intersect	inter;
	t_vector	sphere_to_ray;
	t_tuple		tp1;
	t_tuple		tp2;
	double		a;
	double		b;
	double		c;
	double		d;

	sphere_to_ray = subtract_points(r2.origin, point(0, 0, 0));
	tp1 = vector_tp(r2.direction);
	a = dot(tp1, tp1);
	tp2 = vector_tp(sphere_to_ray);
	b = 2 * dot(tp1, tp2);
	c = dot(tp2, tp2) - 1;
	d = (b * b) - (4 * a * c);
	if (d < 0)
	{
		inter.count = 0;
		inter.t[0] = 0;
		inter.t[1] = 0;
		return (inter);
	}
	inter.count = 2;
	inter.t[0] = (-b - sqrt(d)) / (2 * a);
	inter.t[1] = (-b + sqrt(d)) / (2 * a);
	return (inter);
}

t_intersect local_intersect_plane(t_ray r)
{
	t_intersect	inter;

	if (fabs(r.direction.y) < EPSILON)
	{
		inter.count = 0;
		inter.t[0] = 0;
		inter.t[1] = 0;
		return (inter);
	}
	inter.count = 2;
	inter.t[0] = -r.origin.y / r.direction.y ;
	inter.t[1] = -r.origin.y / r.direction.y ; 
	return (inter);
}

t_intersect	intersect(t_shape s, t_ray r)
{
	t_ray local_ray;

	local_ray = transform(r, inverse(s.transform, 4));
	if (!ft_strncmp(s.shape_name, "sp", 2))
		return (local_intersect_sphere(local_ray));
	else if(!ft_strncmp(s.shape_name, "pl", 2))
		return(local_intersect_plane(local_ray));
	
	printf("\nnever here\n");
	return (local_intersect_sphere(local_ray));		
}

t_intersection	intersection(double value, t_shape object)
{
	t_intersection	i;
	//static int		c;

	// i->object = malloc(sizeof(typeof(object)));
	// if (!c)
	// 	c = 1;
	i.count = 0;
	i.t = value;
	i.object = object;
	i.object.shape_name = object.shape_name;
	return (i);
}

t_intersection	*intersections(t_intersection i1, t_intersection i2)
{
	t_intersection	*ret;

	ret = malloc(sizeof(t_intersection) * 2);
	ret[0] = i1;
	ret[1] = i2;
	return (ret);
}

void	sort_intersections(t_intersection *xs)
{
	int				i;
	int				j;
	t_intersection	a;

	i = 0;
	// printf("count : %d\n", xs[0].count);
	while (xs && i < xs[0].count)
	{
		j = i + 1;
		while (j < xs[0].count)
		{
			if (xs[i].t > xs[j].t)
			{
				a = xs[i];
				xs[i] = xs[j];
				xs[j] = a;
			}
			j++;
		}
		i++;
	}
}

t_intersection	*intersections2(int n, ...)
{
	t_intersection	*ret;
	int				i;
	va_list			inters;

	ret = malloc(sizeof(t_intersection) * n);
	i = 0;
	va_start(inters, n);
	while (i < n)
	{
		ret[i] = va_arg(inters, t_intersection);
		ret[i].count = n;
		i++;
	}

	va_end(inters);
	return (ret);
}

t_intersection	hit(t_intersection *xs)
{
	int				i;
	t_intersection	inter;

	i = 0;
	if (xs)
	{
		sort_intersections(xs);
		while (xs && i < xs[i].count)
		{
			if (xs[i].t > 0.0)
				return(xs[i]);
			i++;
		}
	}
	inter.count = 0;
	inter.t = 0;
	return (inter);
}

t_ray	transform(t_ray r, double **m)
{
	t_ray		ret;
	t_tuple		tp1;
	t_tuple		tp2;
	t_tuple		multi1;
	t_tuple		multi2;
	t_point		p;
	t_vector	vec;

	tp1 = point_tp(r.origin);
	multi1 = matrix_multi_tp(m, tp1);
	tp2 = vector_tp(r.direction);
	multi2 = matrix_multi_tp(m, tp2);
	p = point(multi1.x, multi1.y, multi1.z);
	vec = vector(multi2.x, multi2.y, multi2.z);
	ret.origin = p;
	ret.direction = vec;
	return (ret);
}

void	set_transform(t_shape *s, double **t)
{
	s->transform = t;
}
