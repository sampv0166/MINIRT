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
	m->color.r = 255;
	m->color.g = 255;
	m->color.b = 255;
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200.0;
}
