#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere	s;
	t_vector	n;
	t_point		p;

	s = sphere();
	p = point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3);
	n = normal_at(&s, p);
	printf("-------------------\n");
	printf("The normal on a sphere\n");
	printf("x: %lf, y: %lf, z: %lf\n", n.x, n.y, n.z);
	n = normalize(n);
	printf("-------------------\n");
	printf("The normal is a normalized vector\n");
	printf("x: %lf, y: %lf, z: %lf\n", n.x, n.y, n.z);
}