#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere		s;
	t_intersection	*i1;
	t_intersection	*i2;
	t_intersection	*i;
	t_intersection	**xs;

	s = sphere();
	i1 = intersection(1, &s);
	i2 = intersection(2, &s);
	xs = intersections(i2, i1);
	i = hit(xs);
	printf("-------------------\n");
	printf("The hit and all intersections\n");
	if (i->t)
		printf("t value: %lf\n", i->t);
	else
		printf("nothing");
}
