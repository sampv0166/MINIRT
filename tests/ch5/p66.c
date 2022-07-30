#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere		s;
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	i3;
	t_intersection	i4;
	t_intersection	i;
	t_intersection	*xs;

	s = sphere();
	i1 = intersection(5, s);
	i2 = intersection(7, s);
	i3 = intersection(-3, s);
	i4 = intersection(2, s);
	xs = intersections2(4, i1, i2, i3, i4);
	i = hit(xs);
	printf("-------------------\n");
	printf("The hit and all intersections\n");
	if (i.t)
		printf("t value: %lf\n", i.t);
	else
		printf("nothing");
}
