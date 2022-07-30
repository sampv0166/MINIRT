#include "../includes/minirt.h"

// t_world	world(void)
// {	
// 	t_world	w;

// 	w.s[0] = NULL;
// 	return (w);
// }

t_world	default_world(void)
{
	t_light		light;
	t_sphere	s1;
	t_sphere	s2;
	t_point		p;
	t_color		c1;
	t_color		c2;
	double		**t;
	t_tuple		tp;
	t_world		w;

	p = point(-10, -10, -10);
	c1 = color(1, 1, 1);
	light = point_light(p, c1);
	s1 = sphere();
	c2 = color(0.8, 1.0, 0.6);
	s1.material.color = c2;
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s2 = sphere();
	tp = tuple(0.5, 0.5, 0.5, 1.0);
	t = scaling(tp);
	s2.transform = t;
	w.l = light;
	w.s[0] = s1;
	w.s[1] = s2;
	return (w);
}

void	sort_list(int n, double *num)
{
	int		i;
	int		j;
	double	a;
	
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (num[i] > num[j])
			{
				a = num[i];
				num[i] = num[j];
				num[j] = a;
			}
			j++;
		}
		i++;
	}
}

t_intersection	*intersect_world(t_world w, t_ray r)
{
	t_intersection	*xs;
	t_intersect		inter1;
	t_intersect		inter2;
	double			t[4];
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	i3;
	t_intersection	i4;

	inter1 = intersect(w.s[0], r);
	inter2 = intersect(w.s[1], r);
	t[0] = inter1.t[0];
	t[1] = inter1.t[1];
	t[2] = inter2.t[0];
	t[3] = inter2.t[1];
	sort_list(4, t);
	i1 = intersection(t[0], w.s[0]);
	i2 = intersection(t[1], w.s[0]);
	i3 = intersection(t[2], w.s[1]);
	i4 = intersection(t[3], w.s[1]);
	xs = intersections2(4, i1, i2, i3, i4);
	return (xs);
}

t_comps	prepare_computations(t_intersection i, t_ray r)
{
	t_comps	comps;

	comps.t = i.t;
	comps.object = i.object;
	comps.point = position(r, comps.t);
	comps.eyev = negate_vector(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	if (dot(vector_tp(comps.normalv), vector_tp(comps.eyev)) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate_vector(comps.normalv);
	}
	else
		comps.inside = FALSE;
	return (comps);
}

t_color	shade_hit(t_world w, t_comps comps)
{
	t_color	c;
	
	c = lighting(comps.object.material, w.l, comps.point, comps.eyev, comps.normalv);
	return (c);
}

t_color	color_at(t_world w, t_ray r)
{
	t_intersection	*i;
	t_intersection	h;
	t_comps			comps;

	i = intersect_world(w, r);
	h = hit(i);
	if (h.count == 0)
		return (color(0, 0, 0));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}