#include "../includes/minirt.h"

t_vector	*normal_at(t_sphere *s, t_point *p)
{
	t_vector	*obj_normal;
	t_vector	*world_normal;
	t_point		*point;
	t_point		*obj_point;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_tuple		*tp3;
	t_tuple		*tp4;

	point = malloc(sizeof(t_point));
	obj_point = malloc(sizeof(t_point));
	world_normal = malloc(sizeof(t_vector));
	tp1 = points(p);
	tp2 = matrix_multi_tp(inverse(s->transform, 4), tp1);
	obj_point->x = tp2->x;
	obj_point->y = tp2->y;
	obj_point->z = tp2->z;
	point->x = 0;
	point->y = 0;
	point->z = 0;
	obj_normal = subtract_points(obj_point, point);
	tp3 = vectors(obj_normal);
	tp4 = matrix_multi_tp(transpose(inverse(s->transform, 4)), tp3);
	world_normal->x = tp4->x;
	world_normal->y = tp4->y;
	world_normal->z = tp4->z;
	return (normalize(world_normal));
}

t_vector	*reflect(t_vector *vec, t_vector *normal)
{
	t_vector	*ret;
	double		dot;
	t_tuple		*tp1;
	t_tuple		*tp2;

	ret = malloc(sizeof(t_vector));
	tp1 = malloc(sizeof(t_tuple));
	tp2 = malloc(sizeof(t_tuple));
	tp1 = vectors(vec);
	tp2 = vectors(normal);
	dot = 2 * dot_product(tp1, tp2);
	normal->x = normal->x * dot;
	normal->y = normal->y * dot;
	normal->z = normal->z * dot;
	ret->x = vec->x - normal->x;
	ret->y = vec->y - normal->y;
	ret->z = vec->z - normal->z;
	return (ret);
}

void	point_light(t_point pos, t_color intensity, t_light *point)
{
	t_tuple	*tp;

	tp = points(&pos);
	point->pos = *tp;
	point->color = intensity;
}

void	material(t_material *m)
{
	m->color.r = 1;
	m->color.g = 1;
	m->color.b = 1;
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200.0;
}

t_color	lighting(t_material m, t_light l, t_point pos, t_vector eyev, t_vector normalv)
{
	t_point		effective_color;
	t_vector	*lightv;
	t_vector	*reflectv;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		ret;
	double		light_dot_normal;
	double		reflect_dot_eye;
	double		factor;
	t_point		p1;
	t_tuple		*tp1;
	t_tuple		*tp2;
	t_tuple		*tp3;

	effective_color.x = m.color.r * l.color.r;
	effective_color.y = m.color.g * l.color.g;
	effective_color.z = m.color.b * l.color.b;
	p1.x = l.pos.x;
	p1.y = l.pos.y;
	p1.z = l.pos.z;
	lightv = normalize(subtract_points(&p1, &pos));
	tp1 = scalar_mlp(points(&effective_color), m.ambient);
	ambient.r = tp1->x;
	ambient.g = tp1->y;
	ambient.b = tp1->z;
	light_dot_normal = dot_product(vectors(lightv), vectors(&normalv));
	if (light_dot_normal < 0)
	{
		diffuse.r = 0;
		diffuse.g = 0;
		diffuse.b = 0;
		specular.r = 0;
		specular.g = 0;
		specular.b = 0;
	}
	else
	{
		tp2 = scalar_mlp(points(&effective_color), m.diffuse);
		tp3 = scalar_mlp(tp2, light_dot_normal);
		diffuse.r = tp3->x;
		diffuse.g = tp3->y;
		diffuse.b = tp3->z;
		reflectv = reflect(negate_vector(lightv), &normalv);
		reflect_dot_eye = dot_product(vectors(reflectv), vectors(&eyev));
		if (reflect_dot_eye <= 0)
		{
			specular.r = 0;
			specular.g = 0;
			specular.b = 0;
		}
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
