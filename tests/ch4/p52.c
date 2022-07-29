#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	t_tuple	res;
	t_point	p;
	t_tuple	tp;
	double	coord[6];

	p = point(2, 3, 4);
	tp = point_tp(p);
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	coord[3] = 0;
	coord[4] = 0;
	coord[5] = 1;
	res = shearing(tp, coord);
	printf("-------------------\n");
	printf("A shearing transformation\n");
	printf("transform * p = point(%lf, %lf, %lf)\n", res.x, res.y, res.z);
}