#include "../../includes/minirt.h"

int	main(void)
{
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_bool		in_shadow;
	t_color		res;
	t_material	m;
	t_point		pos;

	m = material();
	pos = point(0, 0, 0);
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	light = point_light(point(0, 0, -10), color(1, 1, 1));
	in_shadow = TRUE;
	res = lighting(m, light, pos, eyev, normalv, in_shadow);
					printf("-------------------\n");
	printf("Lighting with a surface in shadow\n");
	printf("color r: %lf, g: %lf, b: %lf\n", 
		res.r, res.g, res.b);
}
