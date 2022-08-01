#include "../../includes/minirt.h"

/*
First case not working when there is a shadow. It only works
when we have x:10, y:10, z:10 otherwise the determinant is 
showing as negative value and intersect function returns
zero intersects
*/
int	main(void)
{
	t_world	w;
	t_point	p;
	t_bool	res;

	w = default_world();
	p = point(10, -10, 10);
	res = is_shadowed(w, p);
					printf("-------------------\n");
	printf("The shadow when an obj is between point and light\n");
	printf("is_shadowed : %d\n", res);
	p = point(-20, 20, -20);
	res = is_shadowed(w, p);
					printf("-------------------\n");
	printf("There is no shadow when an obj is behind the light\n");
	printf("is_shadowed : %d\n", res);
	p = point(-2, 2, -2);
	res = is_shadowed(w, p);
					printf("-------------------\n");
	printf("There is no shadow when an obj is behind the point\n");
	printf("is_shadowed : %d\n", res);
}
