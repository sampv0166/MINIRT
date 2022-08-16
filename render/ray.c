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

// function check_cap(ray, t)
// x ← ray.origin.x + t * ray.direction.x
// z ← ray.origin.z + t * ray.direction.z
// return (x² + z²) <= 1
// end

t_bool check_cap(t_ray r, double t)
{
	double x;
	double z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;

	if ((pow(x, 2) + pow(z, 2)) <= 1)
		return (TRUE);
	return (FALSE);
}


t_intersect local_intersect_cylinder(void *shape, t_ray r)
{
	t_intersect	inter;
	inter.t[0] = 0 ; 
	inter.t[1] = 0;
	inter.count = 0;
	t_cy *cy;
	cy = (t_cy *) shape;


	double		a;
	double		b;
	double		c;
	double		d;

	double max;
	double min;
		
	max = cy->height / 2.0;
	min = -1.0 * max;

	r.direction =  normalize(r.direction);

	a = (r.direction.x * r.direction.x)  + (r.direction.z * r.direction.z);

	if (a != 0)
	{
		if (chec_approx_zero(a))
		{
			printf("here");
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
		
		double t1;
		double t2;
		t1 = (-b - sqrt(d)) / (2 * a);
		t2 = (-b + sqrt(d)) / (2 * a);

		double temp;
		if (t1 > t2)
		{
			temp = t1;
			t1 = t2;
			t2 = temp;
		}


		double y0;
		double y1;

		y0 = r.origin.y + t1 * r.direction.y;

		if (min < y0 && y0 < max)
		{
			inter.count++;
			inter.t[0] = t1;
		}

		y1 = r.origin.y + t2 * r.direction.y;

		if (min < y1 && y1 < max)
		{
			inter.count++;
			inter.t[1] = t2;	
		}
		//return (inter);
	}
	
	if (chec_approx_zero(r.direction.y))
	{
		inter.count = 0;
		inter.t[0] = 0;
		inter.t[1] = 0;
		return (inter);
	}

	double rt;

	rt = (min - r.origin.y) / r.direction.y;
	if (check_cap(r, rt))
	{
		inter.count++;
		inter.t[0] = rt; 
	}

	rt = (max - r.origin.y) / r.direction.y;
	if (check_cap(r, rt))
	{
		inter.count++;
		inter.t	[1] = rt; 
	}

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
