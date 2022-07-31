#include "../../includes/minirt.h"

int	main(void)
{
	t_point		from;
	t_point		to;
	t_vector	up;
	double		**m;

	from = point(0, 0, 0);
	to = point(0, 0, -1);
	up = vector(0, 1, 0);
	m = view_transform(from, to, up);
			printf("-------------------\n");
	printf("The transformation matrix\n");
	print_matrix(m , 4);
}