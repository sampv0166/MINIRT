#include "../../includes/minirt.h"

int	main(void)
{
	t_camera2	c;
	double		hsize;
	double		vsize;
	double		fov;

	hsize = 160;
	vsize = 120;
	fov = PI / 2;
	c = camera(hsize, vsize, fov);
					printf("-------------------\n");
	printf("Constructing a camera\n");
	printf("camera hsize: %lf, vsize: %lf, field of view: %lf\n",
		c.hsize, c.vsize, c.field_of_view);
	print_matrix(c.transform, 4);
	c = camera(200, 125, PI / 2);
					printf("-------------------\n");
	printf("The pixel size for a horizontal canvas\n");
	printf("c.pixel_size = %lf\n", c.pixel_size);
	c = camera(125, 200, PI / 2);
					printf("-------------------\n");
	printf("The pixel size for a vertical canvas\n");
	printf("c.pixel_size = %lf\n", c.pixel_size);
}