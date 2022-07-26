#include "../includes/minirt.h"

double	**inverse(double **mat, int size)
{
	double	det;
	double	cof;
	double	**res;
	int		i;
	int		j;

	//check how to exit if not invertible
	if (!invertible(mat, size))
	{
		printf("not invertible!\n");
		exit (1);
	}
	res = malloc(sizeof(double *) * size); 
	det = determinant(mat, 4);
	i = 0;
	while (i < size)
	{
		res[i] = malloc(sizeof(double *) * size);
		j = 0;
		while (j < size)
		{
			cof = cofactor(mat, size, j, i);
			res[i][j] = cof/det;
			j++;
		}
		i++;
	}
	return (res);
}