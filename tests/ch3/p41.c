#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	**inv;
	double	**A;
	double	**B;
	double	**C;
	int		res;

	double	elem1[] = {8, -5, 9, 2, 7,
		5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4};
	mat = create_matrix(elem1, 4);
	inv = inverse(mat, 4);
	printf("-------------------\n");
	printf("inverse(A) is the following 4x4 matrix\n");
	print_matrix(inv, 4);
	double	elem2[] = {9, 3, 0, 9, -5,
		-2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2};
	mat = create_matrix(elem2, 4);
	inv = inverse(mat, 4);
	printf("-------------------\n");
	printf("inverse(A) is the following 4x4 matrix\n");
	print_matrix(inv, 4);
	double	elem3[] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	double	elem4[] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};
	A = create_matrix(elem3, 4);
	B = create_matrix(elem4, 4);
	C = matrix_multi(A, B);
	res = matrix_equality(matrix_multi(C, inverse(B, 4)), A, 4);
	printf("-------------------\n");
	printf("Multiplying a product by its inverse\n");
	printf("C * inverse(B) = A (equality test: %d)\n", res);
}