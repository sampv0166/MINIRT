#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	**res;

	double	elem1[] = {0, 9, 3, 0, 9,
		8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8};
	mat = create_matrix(elem1, 4);
	res = transpose(mat);
	printf("-------------------\n");
	printf("Transposing a matrix\n");
	print_matrix(res, 4);
	res = transpose(identity_matrix());
	printf("-------------------\n");
	printf("Transposing the identity matrix\n");
	print_matrix(res, 4);
}
