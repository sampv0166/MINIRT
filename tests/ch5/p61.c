#include "../../includes/minirt.h"

int	main(void)
{
	t_ray		ray;
	t_point		p;
	t_vector	v;
	t_sphere	sp;
	t_intersect	xs;

	p = point(0, 0, 0);
	v = vector(0, 0, 1);
	ray = create_ray(p, v);
	sp = sphere();
	xs = intersect(sp, ray);
	printf("-------------------\n");
	printf("A ray originates inside a sphere\n");
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs.count, xs.value[0], xs.value[1]);
}