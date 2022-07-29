#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	res;

	double	elem[] = {1, 5, -3, 2};
	mat = create_matrix(elem, 2);
	res = determinant(mat, 2);
	printf("-------------------\n");
	printf("Calculating a determinant of a 2x2 matrix\n");
	printf("determinant(A) = %lf\n", res);
}