#include "../includes/minirt.h"

t_color	color(double red, double green, double blue)
{
	t_color	new;

	new.r = red;
	new.g = green;
	new.b = blue;
	return (new);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	return (new);
}

t_color	color_subt(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r - c2.r;
	new.g = c1.g - c2.g;
	new.b = c1.b - c2.b;
	return (new);
}

t_color	color_scale(t_color c, double num)
{
	t_color	new;

	new.r = c.r * num;
	new.g = c.g * num;
	new.b = c.b * num;
	return (new);
}

//also called hadamard product
t_color	color_multi(t_color c1, t_color c2)
{
	t_color	new;

	new.r = c1.r * c2.r;
	new.g = c1.g * c2.g;
	new.b = c1.b * c2.b;
	return (new);
}