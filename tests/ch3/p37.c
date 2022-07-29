#include "../../includes/minirt.h"

int	main(void)
{
	double	**mat;
	double	cof;
	double	det;

	double	elem1[] = {1, 2, 6, -5, 8,
		-4, 2, 6, 4};
	mat = create_matrix(elem1, 3);
	cof = cofactor(mat, 3, 0, 0);
	printf("-------------------\n");
	printf("Calculating a determinant of a 3x3 matrix\n");
	printf("cofactor(A, 0, 0) = ");
	printf("%lf\n", cof);
	cof = cofactor(mat, 3, 0, 1);
	printf("cofactor(A, 0, 1) = ");
	printf("%lf\n", cof);
	cof = cofactor(mat, 3, 0, 2);
	printf("cofactor(A, 0, 2) = ");
	printf("%lf\n", cof);
	det = determinant(mat, 3);
	printf("determinant(A) = ");
	printf("%lf\n", det);
	double	elem2[] = {-2, -8, 3, 5, -3,
		1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
	mat = create_matrix(elem2, 4);
	cof = cofactor(mat, 4, 0, 0);
	printf("-------------------\n");
	printf("Calculating a determinant of a 4x4 matrix\n");
	printf("cofactor(A, 0, 0) = ");
	printf("%lf\n", cof);
	cof = cofactor(mat, 4, 0, 1);
	printf("cofactor(A, 0, 1) = ");
	printf("%lf\n", cof);
	cof = cofactor(mat, 4, 0, 2);
	printf("cofactor(A, 0, 2) = ");
	printf("%lf\n", cof);
	cof = cofactor(mat, 4, 0, 3);
	printf("cofactor(A, 0, 2) = ");
	printf("%lf\n", cof);
	det = determinant(mat, 4);
	printf("determinant(A) = ");
	printf("%lf\n", det);
}