#include "../includes/minirt.h"

double	**transpose(double **mat)
{
	double	**res;
	int	i;
	int	j;

	res = malloc(sizeof(double *) * 4);
	i = 0;
	j = 0;
	while (i < 4)
	{
		res[i] = malloc(sizeof(double) * 4);
		j = 0;
		while (j < 4)
		{
			res[i][j] = mat[j][i];
			j++;
		}
		i++;
	}
	return (res);
}