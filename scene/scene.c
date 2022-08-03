#include "../includes/minirt.h"

// t_world	world(void)
// {	
// 	t_world		w;

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
	t_color		c3;
	//double		**t;
//	t_tuple		tp;
	t_world		w;

	p = point(-10, 10, -10);
	c1 = color(1, 1, 1);
	light = point_light(p, c1);
	s1 = sphere();
	c2 = color(0.8, 1.0, 0.6);
	s1.material.color = c2;
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s1.transform = translation(tuple(-1, 1, 1, 1));
	s2 = sphere();
	//tp = tuple(0.5, 0.5, 0.5, 1.0);
	//t = scaling(tp);
	//s2.transform = t;
	c3 = color(0.5, 1.0, 0.1);
	s2.material.color = c3;
	s2.material.diffuse = 0.7;
	s2.material.specular = 0.2;


	w.l = light;
	w.s[0] = s1;
	w.s[1] = s2;
	return (w);
}

t_intersection	*intersect_world(t_world w, t_ray r)
{
	t_intersection	*xs;
	t_intersect		inter1;
	t_intersect		inter2;
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	i3;
	t_intersection	i4;

	inter1 = intersect(w.s[0], r);
	inter2 = intersect(w.s[1], r);
	// printf("t1: %lf, t2: %lf, t3: %lf, t4: %lf\n",
	// 	inter1.t[0], inter1.t[1], inter2.t[0], inter2.t[1]);
	if (inter1.count > 0 && inter2.count > 0)
	{
		i1 = intersection(inter1.t[0], w.s[0]);
		i2 = intersection(inter1.t[1], w.s[0]);
		i3 = intersection(inter2.t[0], w.s[1]);
		i4 = intersection(inter2.t[1], w.s[1]);
		xs = intersections2(4, i1, i2, i3, i4);
	}
	else if (inter1.count > 0)
	{
		i1 = intersection(inter1.t[0], w.s[0]);
		i2 = intersection(inter1.t[1], w.s[0]);	
		xs = intersections2(2, i1, i2);
	}
	else if (inter2.count > 0)
	{
		i1 = intersection(inter2.t[0], w.s[1]);
		i2 = intersection(inter2.t[1], w.s[1]);
		xs = intersections2(2, i1, i2);
	}
	else
	{
		xs = NULL;
	}

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
	comps.over_point.x = comps.point.x + comps.normalv.x * EPSILON;
	comps.over_point.y = comps.point.y + comps.normalv.y * EPSILON;
	comps.over_point.z = comps.point.z + comps.normalv.z * EPSILON;
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
	t_bool	shadowed;
	
	shadowed = is_shadowed(w, comps.over_point);
	c = lighting(comps.object.material, w.l, comps.over_point, comps.eyev, 
	comps.normalv, shadowed);
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