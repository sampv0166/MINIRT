#include "../includes/minirt.h"

// t_world	world(void)
// {	
// 	t_world		w;

// 	return (w);
// }

t_world	default_world(void)
{
	t_light		light;
	// t_sphere	s1;
	// t_sphere	s2;
	t_point		p;
	t_color		c1;
	t_color		c2;
	t_color		c3;
	//double		**t;
//	t_tuple		tp;
	t_world		w;
	t_shape shape1;
	t_shape shape2;
	t_shape shape3;

	p = point(-10, 10, -10);
	c1 = color(1, 1, 1);
	light = point_light(p, c1);

	int i;
	i = 1;
	shape1 = create_shape(i);
	c2 = color(0.8, 1.0, 0.6);
	shape1.material.color = c2;
	shape1.material.diffuse = 0.7;
	shape1.material.specular = 0.2;
	shape1.transform = translation(tuple(-1, 1, 1, 1));
	shape1.shape_name = "sp";

	shape2 = create_shape(i);
	c3 = color(0.5, 1.0, 0.1);
	shape2.material.color = c3;
	shape2.material.diffuse = 0.7;
	shape2.material.specular = 0.2;
	shape2.shape_name = "sp";
	i = 2;

	shape3 = create_shape(2);
	c3 = color(1, 0.2, 1);
	shape3.material.color = c3;
	shape3.material.diffuse = 0.7;
	shape3.material.specular = 0.2;
	// shape3.transform = rotation_x(1.5707963267948966);
	
	shape3.transform = translation(tuple(0, -2, 0, 1));
	shape3.shape_name = "pl";

	w.l = light;
	w.s[0] = shape1;
	w.s[1] = shape2;
	w.s[2] = shape3;

	return (w);
}

t_intersection	*intersect_world(t_world w, t_ray r)
{
	t_intersection	*xs;
	t_intersect		inter1;
	t_intersect		inter2;
	t_intersect		inter3;
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	i3;
	t_intersection	i4;
	t_intersection	i5;
	t_intersection	i6;

	inter1 = intersect(w.s[0], r);
	inter2 = intersect(w.s[1], r);
	inter3 = intersect(w.s[2], r);
	// printf("t1: %lf, t2: %lf, t3: %lf, t4: %lf\n",
	// 	inter1.t[0], inter1.t[1], inter2.t[0], inter2.t[1]);
	// if (inter3.count == 0)
	// 	
	// if ()
	// {
	// 	i1 = intersection(inter3.t[0], w.s[2]);
	// 	i2 = intersection(inter3.t[1], w.s[2]);
	// 	i3 = intersection(inter2.t[0], w.s[1]);
	// 	i4 = intersection(inter2.t[1], w.s[1]);
	// 	// i5 = intersection(inter2.t[0], w.s[2]);
	// 	// i6 = intersection(inter2.t[1], w.s[2]);
	// 	xs = intersections2(2, i1, i2);
	// }
	if (inter1.count > 0 && inter2.count > 0 && inter3.count > 0)
	{
		i1 = intersection(inter1.t[0], w.s[0]);
		i2 = intersection(inter1.t[1], w.s[0]);
		i3 = intersection(inter2.t[0], w.s[1]);
		i4 = intersection(inter2.t[1], w.s[1]);
		i5 = intersection(inter3.t[0], w.s[2]);
		i6 = intersection(inter3.t[1], w.s[2]);
		xs = intersections2(6, i1, i2, i3, i4, i5, i6);
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
	else if (inter3.count > 0)
	{
		i5 = intersection(inter3.t[0], w.s[2]);
		i6 = intersection(inter3.t[1], w.s[2]);
		xs = intersections2(2, i5, i6);
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
	
	if (!ft_strncmp(comps.object.shape_name, "sp", 2))
		comps.normalv = local_normal_at_sphere(comps.object, comps.point);
	else if (!ft_strncmp(comps.object.shape_name, "pl", 2))
		comps.normalv = vector(0, 1,0);
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
	printf("\n%f\n", h.t);
	if (h.count == 0)
		return (color(0, 0, 0));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}