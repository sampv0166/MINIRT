#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat1;
	double	**mat2;
	double	**res;

	double elem1[] = {1, 2, 3, 4, 5,
		6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	double elem2[] = {-2, 1, 2, 3, 3,
		2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};
	mat1 = create_matrix(elem1, 4);
	mat2 = create_matrix(elem2, 4);
	res = matrix_multi(mat1, mat2);
	printf("-------------------\n");
	printf("Multiplying two matrices\n");
	print_matrix(res, 4);
}
