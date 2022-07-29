#include "../../includes/minirt.h"

int	main(void)
{
	t_material	m;
	t_sphere	s;

	m = material();
	printf("-------------------\n");
	printf("The default material\n");
	printf("r:%lf, g:%lf, b:%lf a:%lf, d:%lf, sp:%lf, sh:%lf\n",
		m.color.r, m.color.g, m.color.b, m.ambient, m.diffuse,
		m.specular, m.shininess);
	s = sphere();
	m.ambient = 1;
	s.material = m;
	printf("-------------------\n");
	printf("A sphere may be assigned a material\n");
	printf("r:%lf, g:%lf, b:%lf a:%lf, d:%lf, sp:%lf, sh:%lf\n",
		s.material.color.r, s.material.color.g, s.material.color.b,
		s.material.ambient, s.material.diffuse,
		s.material.specular, s.material.shininess);
}