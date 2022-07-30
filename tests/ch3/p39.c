#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	**res;
	double	det;

	double	elem1[] = {6, 4, 4, 4, 5,
		5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6};
	mat = create_matrix(elem1, 4);
	det = determinant(mat, 4);
	printf("-------------------\n");
	printf("Testing an invertible matrix for invertibility\n");
	printf("determinant(A) = %lf\n", det);
	printf("A is invertible\n");
	double	elem2[] = {-4, 2, -2, -3, 9,
		6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0};
	mat = create_matrix(elem2, 4);
	det = determinant(mat, 4);
	printf("-------------------\n");
	printf("Testing an noninvertible matrix for invertibility\n");
	printf("determinant(A) = %lf\n", det);
	printf("A is not invertible\n");
	double	elem[] = {-5, 2, 6, -8, 1,
		-5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};
	mat = create_matrix(elem, 4);
	res = inverse(mat, 4);
	printf("-------------------\n");
	printf("B is the following 4x4 matrix\n");
	print_matrix(res, 4);
}