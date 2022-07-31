#include "../../includes/minirt.h"

int	main(void)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	t_tuple		tp;
	double		**m;
	double		**i;
	double		**t;
	int			res;


	from = point(0, 0, 0);
	to = point(0, 0, -1);
	up = vector(0, 1, 0);
	m = view_transform(from, to, up);
			printf("-------------------\n");
	printf("The transformation matrix\n");
	print_matrix(m , 4);
	i = identity_matrix();
	from = point(0, 0, 0);
	to = point(0, 0, 1);
	up = vector(0, 1, 0);
	m = view_transform(from, to, up);
	tp = tuple(-1, 1, -1, 1);
	t = matrix_multi(i, scaling(tp));
	res = matrix_equality(m, t, 4);
				printf("-------------------\n");
	printf("A view transformation matrix looking in +z\n");
	printf("equality result = %d\n", res);
}