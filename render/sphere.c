#include "../includes/minirt.h"
t_vector		local_normal_at_sphere(t_point obj_point, t_point point)
{
	return (subtract_points(obj_point, point));
}

t_vector		local_normal_at_plane()
{
	return (vector(0, 1 ,0));
}

t_vector		local_normal_at_cylinder(void *shape,  t_point pnt)
{
	double max;
	double min;
	t_cy *cy;
	cy = (t_cy *) shape;

	max = cy->height / 2.0;
	min = -1.0 * max;


	// max = 2.0;
	// min = 1.0;

	double dist;

	dist = pow(pnt.x, 2) + pow(pnt.z, 2);
	if (dist < 1 && pnt.y >= max - EPSILON)
		return vector(0, 1, 0);
	else if (dist < 1 && pnt.y <= min + EPSILON)
		return vector(0, -1, 0);
	else
	return (vector(pnt.x, 0 ,pnt.z));
}

t_vector	normal_at(t_shape s, t_point p)
{
	t_vector	obj_normal;
	t_vector	world_normal;
	t_point		point;
	t_point		obj_point;
	t_tuple		tp1;
	t_tuple		tp2;
	t_tuple		tp3;
	t_tuple		tp4;
	double		**invrs;
	double		**trnspose;

	tp1 = point_tp(p);
	invrs = inverse(s.transform, 4);
	tp2 = matrix_multi_tp(invrs, tp1);
	obj_point.x = tp2.x;
	obj_point.y = tp2.y;
	obj_point.z = tp2.z;
	point.x = 0;
	point.y = 0;
	point.z = 0;
	if (!ft_strncmp(s.shape_name, "sp", 2))
		obj_normal = local_normal_at_sphere(obj_point, point);
	if (!ft_strncmp(s.shape_name, "pl", 2))
		obj_normal = local_normal_at_plane(obj_point, point);
	if (!ft_strncmp(s.shape_name, "cy", 2))
		obj_normal = local_normal_at_cylinder(s.shape,obj_point);	
	tp3 = vector_tp(obj_normal);

	trnspose = transpose(invrs);
	tp4 = matrix_multi_tp(trnspose , tp3);
	world_normal.x = tp4.x;
	world_normal.y = tp4.y;
	world_normal.z = tp4.z;

	free_2d_array(invrs,4 );
	free_2d_array(trnspose,4 );
	return (normalize(world_normal));
}

t_vector	reflect(t_vector vec, t_vector normal)
{
	t_vector	ret;
	double		d;

	d = 2 * dot(vector_tp(vec), vector_tp(normal));
	normal.x = normal.x * d;
	normal.y = normal.y * d;
	normal.z = normal.z * d;
	ret.x = vec.x - normal.x;
	ret.y = vec.y - normal.y;
	ret.z = vec.z - normal.z;
	return (ret);
}

t_light	point_light(t_point pos, t_color intensity)
{
	t_light	l;

	l.pos = pos;
	l.color = intensity;
	return (l);
}

t_material	material()
{
	t_material	m;

	m.color.r = 1;
	m.color.g = 1;
	m.color.b = 1;
	m.ambient = 0.1;
	
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	return (m);
}

t_color	lighting(t_material m, t_light l, t_point pos,
	t_vector eyev, t_vector normalv, t_bool in_shadow)
{
	t_point		effective_color;
	t_vector	lightv;
	t_vector	reflectv;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		ret;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;
	t_point		p;
	t_tuple		tp1;
	t_tuple		tp2;
	t_tuple		tp3;

	effective_color.x = m.color.r * l.color.r;
	effective_color.y = m.color.g * l.color.g;
	effective_color.z = m.color.b * l.color.b;
	p = point(l.pos.x, l.pos.y, l.pos.z);
	lightv = normalize(subtract_points(p, pos));
	tp1 = multiply(point_tp(effective_color), m.ambient);
	ambient = color(tp1.x, tp1.y, tp1.z);
	light_dot_normal = dot(vector_tp(lightv), vector_tp(normalv));
	if (light_dot_normal < 0 || in_shadow)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		tp2 = multiply(point_tp(effective_color), m.diffuse);
		tp3 = multiply(tp2, light_dot_normal);
		diffuse = color(tp3.x, tp3.y, tp3.z);
		reflectv = reflect(negate_vector(lightv), normalv);
		reflect_dot_eye = dot(vector_tp(reflectv), vector_tp(eyev));
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, m.shininess);
			specular.r = l.color.r * m.specular * factor;
			specular.g = l.color.g * m.specular * factor;
			specular.b = l.color.b * m.specular * factor;
		}
	}
	ret.r = ambient.r + diffuse.r + specular.r;
	ret.g = ambient.g + diffuse.g + specular.g;
	ret.b = ambient.b + diffuse.b + specular.b;
	return (ret);
}
