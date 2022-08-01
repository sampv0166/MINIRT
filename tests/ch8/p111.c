#include "../../includes/minirt.h"

int	main(void)
{
	t_world	w;
	t_point	p;
	t_bool	res;

	w = default_world();
	p = point(0, 10, 0);
	res = is_shadowed(w, p);
					printf("-------------------\n");
	printf("There is no shadow\n");
	printf("is_shadowed : %d\n", res);
}
