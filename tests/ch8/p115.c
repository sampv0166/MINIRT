#include "../../includes/minirt.h"

int	main(void)
{
	t_ray			r;
	t_sphere		shape;
	t_comps			comps;
	t_intersection	i;
	t_bool			cond1;
	t_bool			cond2;

	r = ray(point(0, 0, -5), vector(0, 0, 1));
	shape = sphere();
	shape.transform = translation(tuple(0, 0, 1, 1));
	i = intersection(5, shape);
	comps = prepare_computations(i, r);
	printf("over point z: %lf, point z: %lf\n",
		comps.over_point.z, comps.point.z);
	cond1 = comps.over_point.z < ((EPSILON * -1) / 2);
	cond2 = comps.point.z > comps.over_point.z;
					printf("-------------------\n");
	printf("Rendering a world with a camera\n");
	printf("comps.over_point.z < -EPSILON / 2 : %d\n",
		cond1);
	printf("comps.point.z > comps.over_point.z : %d\n",
		cond2);
}
