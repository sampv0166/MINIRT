#include "../../includes/minirt.h"

int	main(void)
{
	t_world			w;
	t_ray			r;
	t_intersection	*xs;

	w = default_world();
		printf("-------------------\n");
	printf("Creating a world\n");
	printf("light pos x:%lf, y:%lf, z:%lf\n",
		w.l.pos.x, w.l.pos.y, w.l.pos.z);
	printf("sphere1 id:%d, sphere2 id:%d\n",
		w.s[0].id, w.s[1].id);
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	xs = intersect_world(w, r);
	printf("-------------------\n");
	printf("Intersect a world with a ray\n");
	printf("xs count: %d, value 1: %lf, value 2: %lf, value 3: %lf, value 4: %lf\n", 
		xs[0].count, xs[0].t, xs[1].t, xs[2].t, xs[3].t);
}
