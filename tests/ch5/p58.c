#include "../../includes/minirt.h"

int	main(void)
{
	t_ray		ray;
	t_point		p;
	t_vector	v;
	t_point		pos;

	p = point(1, 2, 3);
	v = vector(4, 5, 6);
	ray = create_ray(p, v);
	printf("-------------------\n");
	printf("Creating and querying a ray\n");
	printf("origin: %lf, %lf, %lf; direction: %lf, %lf, %lf\n",
		ray.origin.x, ray.origin.y, ray.origin.z,
		ray.direction.x, ray.direction.y, ray.direction.z);
	p = point(2, 3, 4);
	v = vector(1, 0, 0);
	ray = create_ray(p, v);
	pos = position(ray, 2.5);
	printf("-------------------\n");
	printf("Computing a point from a distance\n");
	printf("x: %lf, y: %lf, z: %lf\n", pos.x, pos.y, pos.z);
}