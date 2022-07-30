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
	printf("Precomputing the state of an intersection\n");
	printf("comps t = %lf, id: %d\npoint x:%lf y:%lf z:%lf\n",
		comps.t, comps.object.id, comps.point.x, comps.point.y,
		comps.point.z);
	printf("comps eyev x:%lf y:%lf z:%lf\nnormalv x:%lf y:%lf z:%lf\n",
		comps.eyev.x, comps.eyev.y, comps.eyev.z, comps.normalv.x,
		comps.normalv.y, comps.normalv.z);
}