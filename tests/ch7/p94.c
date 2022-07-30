#include "../../includes/minirt.h"

int	main(void)
{
	t_ray			r;
	t_sphere		shape;
	t_intersection	i;
	t_comps			comps;

	r = ray(point(0, 0, -5), vector(0, 0, 1));
	shape = sphere();
	i = intersection(4, shape);
	comps = prepare_computations(i, r);	
			printf("-------------------\n");
	printf("The hit, when an intersection occurs on the outside\n");
	printf("comps.inside = %d\n", comps.inside);
}