#include "../../includes/minirt.h"

int	main(void)
{
	t_sphere	s;
	t_vector	n;
	t_point		p;
	t_tuple		tp;
	double		**m;

	tp = tuple(0, 1, 0, 1);
	s = sphere();
	set_transform(&s, translation(tp));
	p = point(0, 1.70711, -0.70711);
	n = normal_at(&s, p);
	printf("-------------------\n");
	printf("Computing the normal on a translated sphere\n");
	printf("x: %lf, y: %lf, z: %lf\n", n.x, n.y, n.z);
	tp = tuple(1, 0.5, 1, 1);
	s = sphere();
	m = matrix_multi(scaling(tp), rotation_z(PI / 5));
	set_transform(&s, m);
	p = point(0, sqrt(2) / 2, (-1 * sqrt(2)) / 2);
	n = normal_at(&s, p);
	printf("-------------------\n");
	printf("Computing the normal on a transformed sphere\n");
	printf("x: %lf, y: %lf, z: %lf\n", n.x, n.y, n.z);
}
