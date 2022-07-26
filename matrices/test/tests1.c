#include "../../includes/minirt.h"

void	test1(void)
{
	double	elem[16];
	double	**mat;

	elem[0] = 1.0;
	elem[1] = 2.0;
	elem[2] = 3.0;
	elem[3] = 4.0;
	elem[4] = 5.5;
	elem[5] = 6.5;
	elem[6] = 7.5;
	elem[7] = 8.5;
	elem[8] = 9.0;
	elem[9] = 10.0;
	elem[10] = 11.0;
	elem[11] = 12.0;
	elem[12] = 13.5;
	elem[13] = 14.5;
	elem[14] = 15.5;
	elem[15] = 16.5;

	mat = create_matrix(elem, 4);
	print_matrix(mat, 4);
}

void	test2(void)
{
	double	elem[4];
	double	**mat;

	elem[0] = -3;
	elem[1] = 5;
	elem[2] = 1;
	elem[3] = -2;
	mat = create_matrix(elem, 2);
	print_matrix(mat, 2);
}

void	test3(void)
{
	double	elem[9];
	double	**mat;

	elem[0] = -3;
	elem[1] = 5;
	elem[2] = 0;
	elem[3] = 1;
	elem[4] = -2;
	elem[5] = -7;
	elem[6] = 0;
	elem[7] = 1;
	elem[8] = 1;
	mat = create_matrix(elem, 3);
	print_matrix(mat, 3);
}

void	test4(void)
{
	double	elem1[4];
	double	elem2[4];
	double	**mat1;
	double	**mat2;
	int		equal;

	elem1[0] = -3;
	elem1[1] = 5;
	elem1[2] = 1;
	elem1[3] = -2;
	elem2[0] = -3;
	elem2[1] = 3;
	elem2[2] = 1;
	elem2[3] = -2;
	mat1 = create_matrix(elem1, 2);
	mat2 = create_matrix(elem2, 2);
	equal = matrix_equality(mat1, mat2, 2);
	printf("equal: %d\n", equal);
}

void	test5(void)
{
	double	**mat1;
	double	**mat2;
	double	**res;
	double elem1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
	double elem2[] = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};

	mat1 = create_matrix(elem1, 4);
	mat2 = create_matrix(elem2, 4);
	res = matrix_multi(mat1, mat2);
	print_matrix(res, 4);
}

void	test6(void)
{
	double	**mat;
	t_tuple	*tp;
	double	elem[] = {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1};

	mat = create_matrix(elem, 4);
	tp = malloc(sizeof(t_tuple));
	tp->x = 1;
	tp->y = 2;
	tp->z = 3;
	tp->w = 1;
	matrix_multi_tp(mat, tp);
}

void	test7(void)
{
	double	**id;
	double	**mat;
	double	**res;
	t_tuple	*tp;
	double	elem[] = {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32};

	id = identity_matrix();
	mat = create_matrix(elem, 4);
	res = matrix_multi(mat, id);
	print_matrix(res, 4);
	tp = malloc(sizeof(t_tuple));
	tp->x = 1;
	tp->y = 2;
	tp->z = 3;
	tp->w = 4;
	matrix_multi_tp(id, tp);
}

void	test8(void)
{
	double	elem1[] = {0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8};
	double	**mat;
	double	**res;

	mat = create_matrix(elem1, 4);
	res = transpose(mat);
	print_matrix(res, 4);
	print_matrix(identity_matrix(), 4);
}

int	main(void)
{
	test8();
	return (0);
}
