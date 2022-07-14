#include "../includes/minirt.h"

//A vector pointing from p2 to p1
t_vector	*subtract_points(t_point *p1, t_point *p2)
{
	t_vector	*vec;

	vec = malloc(sizeof(t_vector));
	vec->x = p1->x - p2->x;
	vec->y = p1->y - p2->y;
	vec->z = p1->z - p2->z;
	return (vec);
}

t_point	*subtract_vector(t_point *p, t_vector *vec)
{
	t_point	*ret;

	ret = malloc(sizeof(t_vector));
	ret->x = p->x - vec->x;
	ret->y = p->y - vec->y;
	ret->z = p->z - vec->z;
	return (ret);
}
