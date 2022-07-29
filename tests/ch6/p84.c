#include "../../includes/minirt.h"

int	main(void)
{
	t_point	pos;
	t_color	intensity;
	t_light	light;

	pos = point(0, 0, 0);
	intensity = color(1, 1, 1);
	light = point_light(pos, intensity);
	printf("-------------------\n");
	printf("Reflecting a vector approaching at 45deg\n");
	printf("color r:%lf, g:%lf, b:%lf pos x:%lf, y:%lf, Z:%lf\n",
		light.color.r, light.color.g, light.color.b,
		light.pos.x, light.pos.y, light.pos.z);
}