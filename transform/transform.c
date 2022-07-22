#include "../includes/minirt.h"

double	deg(double rad)
{
	double	d;

	d = rad * (180 / PI);
	return (d);
}

double	**translation(t_tuple *tp)
{
	double	**res;

	res = identity_matrix();
	res[0][3] = tp->x; 
	res[1][3] = tp->y; 
	res[2][3] = tp->z;
	res[3][3] = tp->w;
	return (res); 
}

double	**scaling(t_tuple *tp)
{
	double	**res;

	res = identity_matrix();
	res[0][0] = tp->x; 
	res[1][1] = tp->y; 
	res[2][2] = tp->z;
	res[3][3] = 1.0;
	return (res); 
}

double	**rotation_x(double rad)
{
	double	**res;

	res = identity_matrix();
	res[1][1] = cos(rad);
	res[1][2] = -sin(rad);
	res[2][1] = sin(rad);
	res[2][2] = cos(rad);
	print_matrix(res, 4);
	printf("__________________\n");
	return (res);
}