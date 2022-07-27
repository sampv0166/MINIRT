#include "../../includes/minirt.h"

int	main(void)
{
	t_vector	v;
	double		res;

	v = vector(1, 0, 0);
	res = magnitude(v);
	printf("-------------------\n");
	printf("Computing the magnitude of vector(1, 0, 0)\n");
	printf("magnitude(v)  = %lf\n", res);
	v = vector(0, 1, 0);
	res = magnitude(v);
	printf("-------------------\n");
	printf("Computing the magnitude of vector(0, 1, 0)\n");
	printf("magnitude(v)  = %lf\n", res);
	v = vector(0, 0, 1);
	res = magnitude(v);
	printf("-------------------\n");
	printf("Computing the magnitude of vector(0, 0, 1)\n");
	printf("magnitude(v)  = %lf\n", res);
	v = vector(1, 2, 3);
	res = magnitude(v);
	printf("-------------------\n");
	printf("Computing the magnitude of vector(1, 2, 3)\n");
	printf("magnitude(v)  = %lf\n", res);
	v = vector(-1, -2, -3);
	res = magnitude(v);
	printf("-------------------\n");
	printf("Computing the magnitude of vector(-1, -2, -3)\n");
	printf("magnitude(v)  = %lf\n", res);
}