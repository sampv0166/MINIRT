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
	return (res);
}

double	**rotation_y(double rad)
{
	double	**res;

	res = identity_matrix();
	res[0][0] = cos(rad);
	res[0][2] = sin(rad);
	res[2][0] = -sin(rad);
	res[2][2] = cos(rad);
	return (res);
}

double	**rotation_z(double rad)
{
	double	**res;

	res = identity_matrix();
	res[0][0] = cos(rad);
	res[1][0] = sin(rad);
	res[0][1] = -sin(rad);
	res[1][1] = cos(rad);
	return (res);
}

t_tuple	*shearing(t_tuple *tp, double *coord)
{
	double	**mat;
	t_tuple	*res;

	mat = identity_matrix();
	mat[0][1] = coord[0];
	mat[0][2] = coord[1];
	mat[1][0] = coord[2];
	mat[1][2] = coord[3];
	mat[2][0] = coord[4];
	mat[2][1] = coord[5];
	res = matrix_multi_tp(mat, tp);
	return (res);
}