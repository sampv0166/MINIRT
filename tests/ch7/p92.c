#include "../../includes/minirt.h"

int	main(void)
{
	t_world	w;

	world(&w);
		printf("-------------------\n");
	printf("Creating a world\n");
	printf("light pos x:%lf, y:%lf, z:%lf\n",
		w.l.pos.x, w.l.pos.y, w.l.pos.z);
	printf("sphere1 id:%d, sphere2 id:%d\n",
		w.s[0].id, w.s[1].id);
}
