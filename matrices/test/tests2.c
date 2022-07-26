#include "../../includes/minirt.h"

void	test1(void)
{
	double	**mat;
	double	**res;
	double	elem[] = {1, 5, 0, -3, 2, 7, 0, 6, -3};

	mat = create_matrix(elem, 3);
	res = submatrix(mat, 3, 0, 2);
	print_matrix(res, 2);
}

void	test2(void)
{
	double	**mat;
	double	**res;
	double	elem[] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};

	mat = create_matrix(elem, 4);
	res = submatrix(mat, 4, 2, 1);
	print_matrix(res, 3);
}

void	test3(void)
{
	double	elem[] = {3, 5, 0, 2, -1, -7, 6, -1, 5};
	double	**mat;
	double	min;
	double	cof;

	mat = create_matrix(elem, 3);
	min = minor(mat, 3, 1, 0);
	cof = cofactor(mat, 3, 1, 0);
	printf("%lf\n", cof);
}

void	test4(void)
{
	double	elem[] = {1, 2, 6, -5, 8, -4, 2, 6, 4};
	double	**mat;
	double	cof;
	double	det;

	mat = create_matrix(elem, 3);
	cof = cofactor(mat, 3, 0, 2);
	det = determinant(mat, 3);
	printf("%lf\n", det);
}

void	test5(void)
{
	double	elem[] = {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9};
	double	**mat;
	double	cof;
	double	det;

	mat = create_matrix(elem, 4);
	cof = cofactor(mat, 4, 0, 0);
	det = determinant(mat, 4);
	printf("%lf\n", det);
}

void	test6(void)
{
	double	elem1[] = {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6};
	double	elem2[] = {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0};
	double	**mat1;
	double	**mat2;
	
	mat1 = create_matrix(elem1, 4);
	mat2 = create_matrix(elem2, 4);
	printf("invertibility -> matrix 1: %d, matrix 2: %d\n", invertible(mat1, 4), invertible(mat2, 4));
}

void	test7(void)
{
	double	elem[] = {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4};
	double	**mat;
	double	**res;

	mat = create_matrix(elem, 4);
	res = inverse(mat, 4);
	print_matrix(res, 4);
}

void	test8(void)
{
	double	elem[] = {9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2};
	double	**mat;
	double	**inv;

	mat = create_matrix(elem, 4);
	print_matrix(mat, 4);
	printf("____________________\n");
	inv = inverse(mat, 4);
	print_matrix(inv, 4);
}

void	test_bonus(void)
{
	double	elemA[] = {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -1, 1};
	double	elemB[] = {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5};
	double	**A;
	double	**B;
	double	**C;
	int		res;

	A = create_matrix(elemA, 4);
	B = create_matrix(elemB, 4);
	C = matrix_multi(A, B);
	res = matrix_equality(matrix_multi(C, inverse(B, 4)), A, 4);
	printf("result : %d\n", res);
}

int	main(void)
{
	test_bonus();
	return (0);
}