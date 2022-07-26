#include "../includes/minirt.h"

//A vector pointing from p2 to p1
t_vector	subtract_points(t_point p1, t_point p2)
{
	t_vector	vec;

	vec.x = p1.x - p2.x;
	vec.y = p1.y - p2.y;
	vec.z = p1.z - p2.z;
	return (vec);
}

t_point	subtract_vector(t_point p, t_vector vec)
{
	t_point	ret;

	ret.x = p.x - vec.x;
	ret.y = p.y - vec.y;
	ret.z = p.z - vec.z;
	return (ret);
}

//A vector pointing from p2 to p1
void	subtract_points_new(t_point *p1, t_point *p2, t_tuple *tp)
{
	tp->x = p1->x - p2->x;
	tp->y = p1->y - p2->y;
	tp->z = p1->z - p2->z;
	tp->w = 0;
}

t_tuple	subtract(t_tuple a, t_tuple b)
{
	t_tuple	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	ret.w = a.w - b.w;
	return (ret);
}