#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	**res;
	double	det;
	double	min;

	double	elem1[] = {1, 5, 0, -3, 2,
		7, 0, 6, -3};
	mat = create_matrix(elem1, 3);
	res = submatrix(mat, 3, 0, 2);
	printf("-------------------\n");
	printf("A submatrix of a 3x3 matrix is a 2x2 matrix\n");
	print_matrix(res, 2);
	double	elem2[] = {-6, 1, 1, 6, -8,
		5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};
	mat = create_matrix(elem2, 4);
	res = submatrix(mat, 4, 2, 1);
	printf("-------------------\n");
	printf("A submatrix of a 4x4 matrix is a 3x3 matrix\n");
	print_matrix(res, 3);
	double	elem3[] = {3, 5, 0, 2, -1,
		-7, 6, -1, 5};
	mat = create_matrix(elem3, 3);
	res = submatrix(mat, 3, 1, 0);
	det = determinant(res, 2);
	min = minor(mat, 3, 1, 0);
	printf("-------------------\n");
	printf("Calculating a minor of a 3x3 matrix\n");
	printf("determinant(B) = %lf\nminor(A, 1, 0) = %lf\n",
	det, min);
}