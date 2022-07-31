#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere		s;
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	*xs;

	s = sphere();
	i1 = intersection(1, s);
	i2 = intersection(2, s);
	xs = intersections2(2, i1, i2);
	printf("-------------------\n");
	printf("Aggregating intersections and set the object\n");
	printf("t value: %lf object type: %d\n", xs[0].t, xs[0].object.id == s.id);
	printf("t value: %lf object type: %d\n", xs[1].t, xs[1].object.id == s.id);
}