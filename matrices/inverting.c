#include "../includes/minirt.h"

double	determinant(double **mat, int size)
{
	double	res;
	double	tmp;
	int		i;

	if (size == 2)
		res = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
	else
	{
		i = 0;
		res = 0;
		while (i < size)
		{
			tmp = mat[0][i] * cofactor(mat, size, 0, i);
			res = res + tmp;
			i++;
		}
	}
	return (res);
}

double	**submatrix(double **mat, int size, int row, int col)
{
	double	**res;
	double	*elem;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	elem = malloc(sizeof(double) * ((size - 1) * (size - 1)));
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == row || j == col)
			{
				j++;	
				continue ;
			}
			elem[k++] = mat[i][j];
			j++;
		}
		i++;
	}
	res = create_matrix(elem, size - 1);
	return (res);
}

double	minor(double **mat, int size, int row, int col)
{
	double	**submat;
	double	det;

	submat = submatrix(mat, size, row, col);
	det = determinant(submat, size - 1);
	return (det);
}

double	cofactor(double **mat, int size, int row, int col)
{
	double	min;

	min = minor(mat, size, row, col);
	if ((row + col) == 0 || (row + col) % 2 == 0)
		return (min);
	return (min * -1);
}

int	invertible(double **mat, int size)
{
	double	det;
	double	zero;

	det = determinant(mat, size);
	zero = 0.0;
	if (double_equal(det, zero))
		return (0);
	return (1);
}