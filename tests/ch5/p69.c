#include "../../includes/minirt.h"

int	main(void)
{
	t_ray		r1;
	t_ray		r2;
	t_point		p;
	t_vector	v;
	t_tuple		tp;
	t_sphere	s;
	double		**m;
	t_intersect	xs;

	p = point(1, 2, 3);
	v = vector(0, 1, 0);
	tp = tuple(3, 4, 5, 1);
	r1 = create_ray(p, v);
	m = translation(tp);
	r2 = transform(r1, m);
	printf("-------------------\n");
	printf("Translating a ray\n");
	printf("origin: %lf, %lf, %lf\n",
		r2.origin.x, r2.origin.y, r2.origin.z);
	printf("direction: %lf, %lf, %lf\n",
		r2.direction.x, r2.direction.y, r2.direction.z);
	tp = tuple(2, 3, 4, 1);
	m = scaling(tp);
	r2 = transform(r1, m);
	printf("-------------------\n");
	printf("Scaling a ray\n");
	printf("origin: %lf, %lf, %lf\n",
		r2.origin.x, r2.origin.y, r2.origin.z);
	printf("direction: %lf, %lf, %lf\n",
		r2.direction.x, r2.direction.y, r2.direction.z);
	printf("-------------------\n");
	printf("A sphere's default transformation\n");
	s = sphere();
	print_matrix(s.transform, 4);
	printf("-------------------\n");
	printf("Changing a sphere's transformation\n");
	tp = tuple(2, 3, 4, 1);
	m = translation(tp);
	set_transform(&s, m);
	print_matrix(s.transform, 4);
	tp = tuple(2, 2, 2, 1);
	r1 = create_ray(point(0, 0, -5), vector(0, 0, 1));
	set_transform(&s, scaling(tp));
	xs = intersect(s, r1);
	printf("-------------------\n");
	printf("Intersecting a scaled sphere with a ray\n");
	printf("xs count: %d, value 1: %lf, value 2: %lf\n", 
		xs.count, xs.value[0], xs.value[1]);
}
