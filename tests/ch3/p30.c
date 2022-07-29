#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	t_tuple	tp;
	t_tuple	res;

	double	elem[] = {1, 2, 3, 4, 2,
		4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};
	mat = create_matrix(elem, 4);
	tp.x = 1;
	tp.y = 2;
	tp.z = 3;
	tp.w = 1;
	res = matrix_multi_tp(mat, tp);
	printf("-------------------\n");
	printf("A matrix multiplied by a tuple\n");
	printf("A * b = tuple(%lf, %lf, %lf, %lf)\n",
		res.x, res.y, res.z, res.w);
}
