#include "../includes/minirt.h"

t_world	world()
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
	w.s = malloc(sizeof(t_sphere) * 2);
	w.s[0] = s1;
	w.s[1] = s2;
	return (w);
}
