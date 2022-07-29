
#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	**mat1;
	double	**mat2;
	int		equal;

	double	elem1[] = {-3, 5, 1, -2};
	mat = create_matrix(elem1, 2);
	printf("-------------------\n");
	printf("A 2x2 matrix ought to be representable\n");
	print_matrix(mat, 2);
	double	elem2[] = {-3, 5, 0, 1,
		-2, -7, 0, 1, 1};
	mat = create_matrix(elem2, 3);
	printf("-------------------\n");
	printf("A 3x3 matrix ought to be representable\n");
	print_matrix(mat, 3);
	double	elem3[] = {1, 2, 3, 4, 5,
		6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	double	elem4[] = {1, 2, 3, 4, 5,
		6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	mat1 = create_matrix(elem3, 4);
	mat2 = create_matrix(elem4, 4);
	equal = matrix_equality(mat1, mat2, 2);
	printf("-------------------\n");
	printf("Matrix equality with identical matrices\n");
	printf("equal: %d\n", equal);
	double	elem5[] = {2, 3, 4, 5, 6,
		7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	mat1 = create_matrix(elem4, 4);
	mat2 = create_matrix(elem5, 4);
	equal = matrix_equality(mat1, mat2, 2);
	printf("-------------------\n");
	printf("Matrix equality with different matrices\n");
	printf("equal: %d\n", equal);
}
