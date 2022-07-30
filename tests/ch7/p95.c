#include "../../includes/minirt.h"

int	main(void)
{
	t_ray			r;
	t_sphere		shape;
	t_intersection	i;
	t_comps			comps;
	t_world			w;
	t_color			c;

	r = ray(point(0, 0, 0), vector(0, 0, 1));
	shape = sphere();
	i = intersection(1, shape);
	comps = prepare_computations(i, r);	
			printf("-------------------\n");
	printf("The hit, when an intersection occurs on the inside\n");
	printf("point x:%lf y:%lf z:%lf\ncomps.inside = %d\n",
		comps.point.x, comps.point.y, comps.point.z, comps.inside);
	printf("comps eyev x:%lf y:%lf z:%lf\nnormalv x:%lf y:%lf z:%lf\n",
		comps.eyev.x, comps.eyev.y, comps.eyev.z, comps.normalv.x,
		comps.normalv.y, comps.normalv.z);
	w = default_world();
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	shape = w.s[0];
	i = intersection(4, shape);
	comps = prepare_computations(i, r);
	c = shade_hit(w, comps);
				printf("-------------------\n");
	printf("Shading an intersection\n");
	printf("color r: %lf, g: %lf, b: %lf\n", c.r, c.g, c.b);
	w.l = point_light(point(0, 0.25, 0), color(1, 1, 1));
	r = ray(point(0, 0, 0), vector(0, 0, 1));
	shape = w.s[1];
	i = intersection(0.5, shape);
	comps = prepare_computations(i, r);
	c = shade_hit(w, comps);
				printf("-------------------\n");
	printf("Shading an intersection from the inside\n");
	printf("color r: %lf, g: %lf, b: %lf\n", c.r, c.g, c.b);
}