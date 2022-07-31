#include "../../includes/minirt.h"

int	main(void)
{
	t_world			w;
	t_ray			r;
	t_color			c;

	w = default_world();
	r = ray(point(0, 0, -5), vector(0, 1, 0));
	c = color_at(w, r);
			printf("-------------------\n");
	printf("The color when a ray misses\n");
	printf("color r: %lf, g: %lf, b: %lf\n", c.r, c.g, c.b);
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	c = color_at(w, r);
			printf("-------------------\n");
	printf("The color when a ray hits\n");
	printf("color r: %lf, g: %lf, b: %lf\n", c.r, c.g, c.b);
}