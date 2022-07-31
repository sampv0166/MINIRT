#include "../../includes/minirt.h"

int	main(void)
{
	t_camera2	c;
	t_ray		r;
	t_tuple		tp;

	c = camera(201, 101, PI / 2);
	r = ray_for_pixel(c, 100, 50);
					printf("-------------------\n");
	printf("Constructing a ray through the center of the canvas\n");
	printf("r.origin x: %lf, y: %lf, z: %lf\n",
		r.origin.x, r.origin.y, r.origin.z);
	printf("r.direction x: %lf, y: %lf, z: %lf\n",
		r.direction.x, r.direction.y, r.direction.z);
	c = camera(201, 101, PI / 2);
	r = ray_for_pixel(c, 0, 0);
					printf("-------------------\n");
	printf("Constructing a ray through a corner of the canvas\n");
		printf("r.origin x: %lf, y: %lf, z: %lf\n",
		r.origin.x, r.origin.y, r.origin.z);
	printf("r.direction x: %lf, y: %lf, z: %lf\n",
		r.direction.x, r.direction.y, r.direction.z);
	c = camera(201, 101, PI / 2);
	tp = tuple(0, -2, 5, 1);
	c.transform = matrix_multi(rotation_y(PI / 4), translation(tp));
	r = ray_for_pixel(c, 100, 50);
					printf("-------------------\n");
	printf("Constructing a ray when the camera is transformed\n");
		printf("r.origin x: %lf, y: %lf, z: %lf\n",
		r.origin.x, r.origin.y, r.origin.z);
	printf("r.direction x: %lf, y: %lf, z: %lf\n",
		r.direction.x, r.direction.y, r.direction.z);
}
