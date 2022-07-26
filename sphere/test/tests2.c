#include "../../includes/minirt.h"

void	test1(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	// t_vector	v[2];
	t_light		light;
	t_point		point;
	t_color		color;
	t_color		color2;

	// v[0] = eyev;
	// v[1] = normalv;
	eyev.x = 0;
	eyev.y = 0;
	eyev.z = -1;
	normalv.x = 0;
	normalv.y = 0;
	normalv.z = -1;
	point.x = 0;
	point.y = 0;
	point.z = -10;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	material(&m);
	point_light(point, color, &light);
	color2 = lighting(m, light, pos, eyev, normalv);
	printf("color r:%lf, g:%lf, b:%lf\n",
		color2.r, color2.g, color2.b);
}

void	test2(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_point		point;
	t_color		color;
	t_color		color2;

	eyev.x = 0;
	eyev.y = sqrt (2) / 2;
	eyev.z = (sqrt(2) / 2) * -1;
	normalv.x = 0;
	normalv.y = 0;
	normalv.z = -1;
	point.x = 0;
	point.y = 0;
	point.z = -10;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	material(&m);
	point_light(point, color, &light);
	color2 = lighting(m, light, pos, eyev, normalv);
	printf("color r:%lf, g:%lf, b:%lf\n",
		color2.r, color2.g, color2.b);
}

void	test3(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_point		point;
	t_color		color;
	t_color		color2;

	eyev.x = 0;
	eyev.y = 0;
	eyev.z = -1;
	normalv.x = 0;
	normalv.y = 0;
	normalv.z = -1;
	point.x = 0;
	point.y = 10;
	point.z = -10;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	material(&m);
	point_light(point, color, &light);
	color2 = lighting(m, light, pos, eyev, normalv);
	printf("color r:%lf, g:%lf, b:%lf\n",
		color2.r, color2.g, color2.b);
}

void	test4(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_point		point;
	t_color		color;
	t_color		color2;

	eyev.x = 0;
	eyev.y = (sqrt(2) / 2) * -1;
	eyev.z = (sqrt(2) / 2) * -1;
	normalv.x = 0;
	normalv.y = 0;
	normalv.z = -1;
	point.x = 0;
	point.y = 10;
	point.z = -10;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	material(&m);
	point_light(point, color, &light);
	color2 = lighting(m, light, pos, eyev, normalv);
	printf("color r:%lf, g:%lf, b:%lf\n",
		color2.r, color2.g, color2.b);
}

void	test5(void)
{
	t_material	m;
	t_point		pos;
	t_vector	eyev;
	t_vector	normalv;
	t_light		light;
	t_point		point;
	t_color		color;
	t_color		color2;

	eyev.x = 0;
	eyev.y = 0;
	eyev.z = -1;
	normalv.x = 0;
	normalv.y = 0;
	normalv.z = -1;
	point.x = 0;
	point.y = 0;
	point.z = 10;
	color.r = 1;
	color.g = 1;
	color.b = 1;
	pos.x = 0;
	pos.y = 0;
	pos.z = 0;
	material(&m);
	point_light(point, color, &light);
	color2 = lighting(m, light, pos, eyev, normalv);
	printf("color r:%lf, g:%lf, b:%lf\n",
		color2.r, color2.g, color2.b);
}

int	main(void)
{
	test5();
	return (0);
}
