#include "../includes/minirt.h"

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

t_sphere	*sphere()
{
	t_sphere	*sp;

	sp = malloc(sizeof(t_sphere));
	static int	id;
	
	if (!id)
		id = 0;
	sp->id = id++;
	return (sp);
}

t_intersect	local_intersect_sphere(t_ray r)
{
	t_intersect	inter;
	t_vector	sphere_to_ray;
	t_tuple		tp1;
	t_tuple		tp2;

	t_point		origin;
	double		a;
	double		b;
	double		c;
	double		d;

	origin = point(0, 0, 0);
	sphere_to_ray = subtract_points(r.origin, origin);
	tp1 = vector_tp(r.direction);
	a = dot(tp1, tp1);
	tp2 = vector_tp(sphere_to_ray);
	b = 2 * dot(tp1, tp2);
	c = dot(tp2, tp2) - 1;
	d = pow(b, 2) - 4 * a * c;
	
	// printf("d: %lf\n", d);
	if (d < 0)
	{
		inter.count = 0;
		inter.t[0] = 0;
		inter.t[1] = 0;
		return (inter);
	}
	else if (d == 0)
	{
		inter.count = 2;
		inter.t[0] = (-b - sqrt(d)) / (2 * a);
		inter.t[1] = 0;
	}
	inter.count = 2;
	inter.t[0] = (-b - sqrt(d)) / (2 * a);
	inter.t[1] = (-b + sqrt(d)) / (2 * a);
	return (inter);
}
int chec_approx_zero(double a)
{
	double temp = fabs(a - 0);

	if(temp < EPSILON)
	{
		return 1;
	}
	return 0;
}

t_intersect local_intersect_cylinder(t_ray r)
{
	t_intersect	inter;
	double		a;
	double		b;
	double		c;
	double		d;

	a = (r.direction.x * r.direction.x)  + (r.direction.z * r.direction.z);

	if (chec_approx_zero(a))
	{
		inter.count = 0;
		inter.t[0] = 0;
		inter.t[1] = 0;
		return (inter);
	}

	b = 2 * r.origin.x * r.direction.x  + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	d = b * b - 4 * a * c;

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
	inter.t[1] = 0; 
	return (inter);
}

t_intersection	intersection(double value, t_shape object, int count)
{
	t_intersection	i;

	//i = malloc(sizeof(t_intersection));

	i.count = count;
	i.t = value;
	i.object = object;
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
	//printf("\nitss here\n");
	inter.count = 0;
	inter.t = 0;
	//inter.object = xs->object;
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