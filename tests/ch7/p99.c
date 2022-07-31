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


	i = identity_matrix();
	from = point(0, 0, 8);
	to = point(0, 0, 0);
	up = vector(0, 1, 0);
	m = view_transform(from, to, up);
	tp = tuple(0, 0, -8, 1);
	t = matrix_multi(i, translation(tp));
	res = matrix_equality(m, t, 4);
				printf("-------------------\n");
	printf("The view transformation moves the world\n");
	printf("equality result = %d\n", res);
	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	m = view_transform(from, to, up);
				printf("-------------------\n");
	printf("An arbitrary view transformation\n");
	print_matrix(m, 4);
}