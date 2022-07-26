#include "../../includes/minirt.h"

void	test1(void)
{
	t_world	w;

	world(&w);
}

void	test2(void)
{
	t_world	w;

	world(&w);
	printf("light pos x:%lf, y:%lf, z:%lf\n",
		w.l.pos.x, w.l.pos.y, w.l.pos.z);
	printf("sphere1 id:%d, sphere2 id:%d\n",
		w.s[0].id, w.s[1].id);
}

int	main(void)
{
	test2();
	return (0);
}
