#include "../includes/minirt.h"

double	magnitude(t_vector *vec)
{
	double	ret;
	double	sum;

	vec->x = pow(vec->x, 2);
	vec->y = pow(vec->y, 2);
	vec->z = pow(vec->z, 2);
	sum = vec->x + vec->y + vec->z;
	ret = sqrt(sum);
	return (ret);
}

t_vector	*normalize(t_vector *vec)
{
	t_vector	*ret;
	double		mag;

	ret = malloc (sizeof(t_vector));
	mag = magnitude(vec);
	ret->x = vec->x / mag;
	ret->y = vec->y / mag;
	ret->z = vec->z / mag;
	return (ret);
}

double	dot_product(t_vector *vec1, t_vector *vec2)
{
	double	ret;

	ret = vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z;
	return (ret);
}

t_vector	*cross_product(t_vector *vec1, t_vector *vec2)
{
	t_vector	*ret;

	ret = malloc (sizeof(t_vector));
	ret->x = vec1->y * vec2->z - vec1->z * vec2->y;
	ret->y = vec1->z * vec2->x - vec1->x * vec2->z;
	ret->z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (ret);	
}
