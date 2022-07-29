#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	min;
	double	cof;

	double	elem[] = {3, 5, 0, 2, -1,
		-7, 6, -1, 5};
	mat = create_matrix(elem, 3);
	min = minor(mat, 3, 0, 0);
	cof = cofactor(mat, 3, 0, 0);
	printf("-------------------\n");
	printf("minor(A, 0, 0) = ");
	printf("%lf\n", min);
	printf("cofactor(A, 0, 0) = ");
	printf("%lf\n", cof);
	min = minor(mat, 3, 1, 0);
	cof = cofactor(mat, 3, 1, 0);
	printf("-------------------\n");
	printf("minor(A, 0, 0) = ");
	printf("%lf\n", min);
	printf("cofactor(A, 0, 0) = ");
	printf("%lf\n", cof);
}