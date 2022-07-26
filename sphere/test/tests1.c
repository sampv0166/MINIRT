#include "../../includes/minirt.h"

void	test1(void)
{
	t_sphere	*s;
	t_vector	*n;
	t_point		*point;

	n = malloc(sizeof(t_vector));
	point = malloc(sizeof(t_point));
	s = sphere();
	point->x = sqrt(3)/3;
	point->y = sqrt(3)/3;
	point->z = sqrt(3)/3;
	n = normal_at(s, point);
	// n = normalize(n);
	printf("x: %lf, y: %lf, z: %lf\n", n->x, n->y, n->z);
}

void	test2(void)
{
	t_sphere	*s;
	t_vector	*n;
	t_point		*point;
	t_tuple		*tp;

	n = malloc(sizeof(t_vector));
	point = malloc(sizeof(t_point));
	tp = malloc(sizeof(t_tuple));
	tp->x = 0;
	tp->y = 1;
	tp->z = 0;
	tp->w = 1;
	s = sphere();
	set_transform(s, translation(tp));
	point->x = 0;
	point->y = 1.70711;
	point->z = -0.70711;
	n = normal_at(s, point);
	// n = normalize(n);
	printf("x: %lf, y: %lf, z: %lf\n", n->x, n->y, n->z);

}

void	test3(void)
{
	t_sphere	*s;
	t_vector	*n;
	t_point		*point;
	t_tuple		*tp;
	double		**m;

	n = malloc(sizeof(t_vector));
	point = malloc(sizeof(t_point));
	tp = malloc(sizeof(t_tuple));
	tp->x = 1;
	tp->y = 0.5;
	tp->z = 1;
	tp->w = 1;
	s = sphere();
	m = matrix_multi(scaling(tp), rotation_z(PI / 5));
	set_transform(s, m);
	point->x = 0;
	point->y = sqrt(2) / 2;
	point->z = (-1 * sqrt(2)) / 2;
	n = normal_at(s, point);
	// n = normalize(n);
	printf("x: %lf, y: %lf, z: %lf\n", n->x, n->y, n->z);
}

void	test4(void)
{
	t_vector	*v;
	t_vector	*n;
	t_vector	*ref;

	v = malloc(sizeof(t_vector));
	n = malloc(sizeof(t_vector));
	v->x = 1;
	v->y = -1;
	v->z = 0;
	n->x = 0;
	n->y = 1;
	n->z = 0;
	ref = reflect(v, n);
	printf("x: %lf, y: %lf, z: %lf\n", ref->x, ref->y, ref->z);
}

void	test5(void)
{
	t_vector	*v;
	t_vector	*n;
	t_vector	*ref;

	v = malloc(sizeof(t_vector));
	n = malloc(sizeof(t_vector));
	v->x = 0;
	v->y = -1;
	v->z = 0;
	n->x = sqrt(2) / 2;
	n->y = sqrt(2) / 2;
	n->z = 0;
	ref = reflect(v, n);
	printf("x: %lf, y: %lf, z: %lf\n", ref->x, ref->y, ref->z);
}

void	test6(void)
{
	t_point	pos;
	t_color	intensity;
	t_light	point;

	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	intensity.r = 255;
	intensity.g = 255;
	intensity.b = 255;
	point_light(pos, intensity, &point);
	printf("color r:%lf, g:%lf, b:%lf pos x:%lf, y:%lf, Z:%lf\n",
		point.color.r, point.color.g, point.color.b,
		point.pos.x, point.pos.y, point.pos.z);
}

void	test7(void)
{
	t_material	m;

	material(&m);
	printf("r:%lf, g:%lf, b:%lf a:%lf, d:%lf, sp:%lf, sh:%lf\n",
		m.color.r, m.color.g, m.color.b, m.ambient, m.diffuse,
		m.specular, m.shininess);
}

void	test8(void)
{
	t_sphere	*s;
	t_material	m;

	s = sphere();
	material(&m);
	m.ambient = 1;
	s->material = m;
	printf("r:%lf, g:%lf, b:%lf a:%lf, d:%lf, sp:%lf, sh:%lf\n",
		s->material.color.r, s->material.color.g, s->material.color.b,
		s->material.ambient, s->material.diffuse,
		s->material.specular, s->material.shininess);
}

int	main(void)
{
	test8();
	return (0);
}