#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere		s;
	t_intersection	*i;

	s = sphere();
	i = intersection(3.5, &s);
	printf("-------------------\n");
	printf("An intersection encapsulates t and object\n");
	printf("t value: %lf object id: %d\n", i->t, i->object->id);
}