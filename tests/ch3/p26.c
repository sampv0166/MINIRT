#include "../../includes/minirt.h"

int	main(void)
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
	printf("-------------------\n");
	printf("Constructing and inspecting a 4x4 matrix\n");
	print_matrix(mat, 4);
}