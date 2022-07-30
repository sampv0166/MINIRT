#include "../../includes/minirt.h"

int	main(void)
{	
	t_ray		r;
	t_sphere	s;
	t_tuple		tp;
	t_intersect	xs;

	s = sphere();
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	tp = tuple(5, 0, 0, 1);
	set_transform(&s, translation(tp));
	print_matrix(s.transform, 4);
	xs = intersect(s, r);
	printf("-------------------\n");
	printf("Intersecting a translated sphere with a ray\n");
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs.count, xs.t[0], xs.t[1]);
}