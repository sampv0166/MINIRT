#include "../../includes/minirt.h"

int	main(void)
{
	t_color	res;

	res = color(-0.5, 0.4, 1.7);
	printf("-------------------\n");
	printf("Colors are (red, green, blue) tuples\n");
	printf("c.red:%lf, c.blue:%lf, c.green:%lf\n",
		res.r, res.g, res.b);
}