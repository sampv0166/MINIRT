#include "../../includes/minirt.h"

int	main(void)
{
	t_ray		r;
	t_point		p;
	t_vector	v;
	t_sphere	sp;
	t_intersect	xs;

	p = point(0, 0, -5);
	v = vector(0, 0, 1);
	r = ray(p, v);
	sp = sphere();
	printf("-------------------\n");
	printf("A ray intersects a sphere at two points\n");
	printf("sphere id: %d; center x: %lf, y: %lf, z: %lf; rad: %lf;\n",
		sp.id, sp.sp_center.x, sp.sp_center.y, sp.sp_center.z,
		sp.radius);
	xs = intersect(sp, r);
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs.count, xs.t[0], xs.t[1]);
}
