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
	// printf("p x:%lf, y:%lf, z:%lf\n", p.x, p.y, p.z);
	r = ray(p, direction);
	// printf("r.origin x: %lf, y: %lf, z: %lf\n",
	// 	r.origin.x, r.origin.y, r.origin.z);
	// printf("r.direction x: %lf, y: %lf, z: %lf\n",
	// 	r.direction.x, r.direction.y, r.direction.z);
	xs = intersect_world(w, r);
	// printf("xs count:%d, xs0: %lf, xs1: %lf, xs2: %lf, xs4: %lf\n",
	// 	xs[0].count, xs[0].t, xs[1].t, xs[2].t, xs[3].t);
	if (xs)
	{
		h = hit(xs);
		// printf("h value: %lf\n", h.t);
		if (h.t && h.t < distance)
			return TRUE;
		else
			return FALSE;	
	}
	else
		return FALSE;
}