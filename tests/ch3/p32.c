#include "../../includes/minirt.h"

int	main(void)
{
	double	**id;
	double	**mat;
	double	**res;
	t_tuple	tp;
	t_tuple	new;

	double	elem[] = {0, 1, 2, 4, 1,
		2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};
	id = identity_matrix();
	mat = create_matrix(elem, 4);
	res = matrix_multi(mat, id);
	printf("-------------------\n");
	printf("Multiplying a matrix by the identity matrix\n");
	print_matrix(res, 4);
	tp.x = 1;
	tp.y = 2;
	tp.z = 3;
	tp.w = 4;
	new = matrix_multi_tp(id, tp);
	printf("-------------------\n");
	printf("Multiplying the identity matrix by a tuple\n");
	printf("A * b = tuple(%lf, %lf, %lf, %lf)\n",
		new.x, new.y, new.z, new.w);
}
