#include "../../includes/minirt.h"

int	main(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_point		p;
	t_color		c1;
	t_color		c2;

	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	p = point(0, 0, 10);
	c1 = color(1, 1, 1);
	light = point_light(p, c1);
	c2 = lighting(m, light, pos, eyev, normalv);
		printf("-------------------\n");
	printf("Lighting with eye opp surface, light offset 45deg\n");
	printf("color r:%lf, g:%lf, b:%lf\n",
		c2.r, c2.g, c2.b);
}