#include "../includes/minirt.h"

t_color	*color(double red, double green, double blue)
{
	t_color	*new;

	new = malloc(sizeof(t_color));
	new->r = red;
	new->g = green;
	new->b = blue;
	return (new);
}

t_color	*color_add(t_color *c1, t_color *c2)
{
	t_color	*new;
	
	new = malloc(sizeof(t_color));
	new->r = MAX(c1->r + c2->r, 255.0);
	new->g = MAX(c1->g + c2->g, 255.0);
	new->b = MAX(c1->b + c2->b, 255.0);
	return (new);
}

t_color	*color_subt(t_color *c1, t_color *c2)
{
	t_color	*new;
	
	new = malloc(sizeof(t_color));
	new->r = MIN(c1->r - c2->r, 0.0);;
	new->g = MIN(c1->g - c2->g, 0.0);
	new->b = MIN(c1->b - c2->b, 0.0);
	return (new);
}

t_color	*color_scale(t_color *c, double num)
{
	t_color	*new;
	
	new = malloc(sizeof(t_color));
	new->r = MAX(c->r * num, 255.0);
	new->g = MAX(c->g * num, 255.0);
	new->b = MAX(c->b * num, 255.0);
	return (new);
}

//also called hadamard product
t_color	*color_multi(t_color *c1, t_color *c2)
{
	t_color	*new;
	
	new = malloc(sizeof(t_color));
	new->r = MAX(c1->r * c2->r, 255.0);
	new->g = MAX(c1->g * c2->g, 255.0);
	new->b = MAX(c1->b * c2->b, 255.0);
	return (new);
}