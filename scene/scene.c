#include "../includes/minirt.h"

void	world(t_world *w)
{
	t_light		light;
	t_sphere	*s1;
	t_sphere	*s2;
	t_point		p;
	t_color		c1;
	t_color		c2;
	double		**t;
	t_tuple		tp;

	p.x = -10;
	p.y = -10;
	p.z = -10;
	c1.r = 1;
	c1.g = 1;
	c1.b = 1;
	point_light(p, c1, &light);
	s1 = sphere();
	c2.r = 0.8;
	c2.g = 1.0;
	c2.b = 0.6;
	s1->material.color = c2;
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = sphere();
	tp.x = 0.5;
	tp.y = 0.5;
	tp.z = 0.5;
	tp.w = 1.0;
	t = scaling(&tp);
	s2->transform = t;
	w->l = light;
	w->s = malloc(sizeof(t_sphere) * 2);
	w->s[0] = *s1;
	w->s[1] = *s2;
}
