#include "../includes/minirt.h"

t_tuple	*vectors(t_vector *vec)
{
	t_tuple	*tp;

	tp = malloc(sizeof(t_tuple));
	tp->x = vec->x;
	tp->y = vec->y;
	tp->z = vec->z;
	tp->w = 0.0;
	return (tp);
}

t_tuple	*points(t_point *dot)
{
	t_tuple	*tp;

	tp = malloc(sizeof(t_tuple));
	tp->x = dot->x;
	tp->y = dot->y;
	tp->z = dot->z;
	tp->w = 1.0;
	return (tp);
}

int	type(t_tuple *tp)
{
	if (tp->w == 1.0)
		return (1);
	return (0);
}

t_tuple	*add_tuple(t_tuple *a, t_tuple *b)
{
	t_tuple	*tp;

	tp = malloc(sizeof(t_tuple));
	tp->x = (a->x + b->x);
	tp->y = (a->y + b->y);
	tp->z = (a->z + b->z);
	tp->w = (a->w + b->w);
	return (tp);
}

double	dot_product(t_tuple *a, t_tuple *b)
{
	double	ret;

	ret = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
	return (ret);
}