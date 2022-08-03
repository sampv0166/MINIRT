#include "../includes/minirt.h"

t_bool	is_shadowed(t_world w, t_point p)
{
	t_vector		v;
	double			distance;
	t_vector		direction;
	t_ray			r;
	t_intersection	*xs;
	t_intersection	h;

	v = subtract_points(w.l.pos, p);
	distance = magnitude(v);
	direction = normalize(v);
	r = ray(p, direction);
	xs = intersect_world(w, r);
	h = hit(xs);
	if (h.t && h.t < distance)
		return TRUE;
	else
		return FALSE;
}