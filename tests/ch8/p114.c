#include "../../includes/minirt.h"

int	main(void)
{
	t_world			w;
	t_sphere		s1;
	t_sphere		s2;
	t_ray			r;
	t_intersection	i;
	t_comps			comps;
	t_color			c;

	w.l = point_light(point(0, 0, 0), color(1, 1, 1));
	s1 = sphere();
	w.s[0] = s1;
	s2 = sphere();
	s2.transform = translation(tuple(0, 0, 10, 1));
	w.s[1] = s2;
	r = ray(point(0, 0, 5), vector(0, 0, 1));
	i = intersection(4, s2);
	comps = prepare_computations(i, r);
	c = shade_hit(w, comps);
					printf("-------------------\n");
	printf("shade_hit() is given an intersection in shadow\n");
	printf("color r: %lf, g: %lf, b: %lf\n", c.r, c.g, c.b);
}
