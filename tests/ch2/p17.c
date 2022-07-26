#include "../../includes/minirt.h"

int	main(void)
{
	t_color	a;
	t_color	b;
	t_color	res;

	a = color(0.9, 0.6, 0.75);
	b = color(0.7, 0.1, 0.25);
	res = color_add(a, b);
	printf("-------------------\n");
	printf("Adding colors\n");
	printf("c.red:%lf, c.blue:%lf, c.green:%lf\n",
		res.r, res.g, res.b);
	a = color(0.9, 0.6, 0.75);
	b = color(0.7, 0.1, 0.25);
	res = color_subt(a, b);
	printf("-------------------\n");
	printf("Subtracting colors\n");
	printf("c.red:%lf, c.blue:%lf, c.green:%lf\n",
		res.r, res.g, res.b);
	a = color(0.2, 0.3, 0.4);
	res = color_scale(a, 2);
	printf("-------------------\n");
	printf("Multiplying colors by a scalar\n");
	printf("c.red:%lf, c.blue:%lf, c.green:%lf\n",
		res.r, res.g, res.b);
	a = color(1, 0.2, 0.4);
	b = color(0.9, 1, 0.1);
	res = color_multi(a, b);
	printf("-------------------\n");
	printf("Multiplying colors\n");
	printf("c.red:%lf, c.blue:%lf, c.green:%lf\n",
		res.r, res.g, res.b);
}