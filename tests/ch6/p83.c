#include "../../includes/minirt.h"

int	main(void)
{
	t_vector	v;
	t_vector	n;
	t_vector	ref;

	v = vector(1, -1, 0);
	n = vector(0, 1, 0);
	ref = reflect(v, n);
	printf("-------------------\n");
	printf("Reflecting a vector approaching at 45deg\n");
	printf("x: %lf, y: %lf, z: %lf\n", ref.x, ref.y, ref.z);
	v = vector(0, -1, 0);
	n = vector(sqrt(2) / 2, sqrt(2) / 2, 0);
	ref = reflect(v, n);
	printf("-------------------\n");
	printf("Reflecting a vector approaching off a slanted surface\n");
	printf("x: %lf, y: %lf, z: %lf\n", ref.x, ref.y, ref.z);
}