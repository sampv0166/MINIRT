#include "../includes/minirt.h"

double	**create_matrix(double *elem, int col)
{
	double	**mat;
	int		i;
	int		j;
	int		k;

	mat = malloc(sizeof(double *) * col);
	i = 0;
	k = 0;
	while (i < col)
	{
		mat[i] = malloc(sizeof(double) * col);
		j = 0;
		while (j < col)
		{
			mat[i][j] = elem[k++];
			j++;
		}
		i++;
	}
	return (mat);
}

void	print_matrix(double **mat, int col)
{
	int		i;
	int		j;

	i = 0;
	if (!mat)
		return ;
	while (i < col)
	{
		j = 0;
		while (j < col)
		{
			printf("| %lf\t", mat[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
}

int	matrix_equality(double **mat1, double **mat2, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < col)
	{
		j = 0;
		while (j < col)
		{
			if (!equal(mat1[i][j], mat2[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

double	**matrix_multi(double **mat1, double **mat2)
{
	double	**res;
	int		i;
	int		j;

	res = malloc(sizeof(double *) * 4);
	i = 0;
	while (i < 4)
	{
		res[i] = malloc(sizeof(double) * 4);
		j = 0;
		while (j < 4)
		{
			res[i][j] = mat1[i][0] * mat2[0][j]
				+ mat1[i][1] * mat2[1][j]
				+ mat1[i][2] * mat2[2][j]
				+ mat1[i][3] * mat2[3][j];
			// printf("%lf\n", res[i][j]);
			j++;
		}
		i++;
	}
	return (res);
}

t_tuple	*matrix_multi_tp(double **mat, t_tuple *tp)
{
	t_tuple	*res;
	double	tmp[4];
	int		i;

	res = malloc(sizeof(t_tuple));
	i = 0;
	while (i < 4)
	{
		tmp[i] = mat[i][0] * tp->x
			+ mat[i][1] * tp->y
			+ mat[i][2] * tp->z
			+ mat[i][3] * tp->w;
		// printf("%lf\n", res[i][j]);
		i++;
	}
	res->x = tmp[0];
	res->y = tmp[1];
	res->z = tmp[2];
	res->w = tmp[3];
	return (res);
}
