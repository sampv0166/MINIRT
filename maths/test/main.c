#include "../../includes/minirt.h"

//trying out test cases to see if everything works before moving on
int	main(void)
{
	t_vector	*test1;
	t_vector	*test2;
	t_vector	*result;

	test1 = malloc(sizeof(t_vector));
	test2 = malloc(sizeof(t_vector));
	// result = malloc(sizeof(t_vector));
	test1->x = 1;
	test1->y = 2;
	test1->z = 3;
	test2->x = 2;
	test2->y = 3;
	test2->z = 4;
	result = cross_product(test2, test1);
	// printf("result: %lf\n", result);
	printf("x: %lf, y: %lf, z: %lf\n", result->x, result->y, result->z);
	return (0);
}