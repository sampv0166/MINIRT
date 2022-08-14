#include "../includes/minirt.h"

double	**view_transform(t_point from, t_point to, t_vector up)
{
	double		**m;
	t_vector	forward;
	t_vector	left;
	t_vector	true_up;
	t_tuple		tp;

	forward = normalize(subtract_points(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	m = identity_matrix();
	m[0][0] = left.x;
	m[0][1] = left.y;
	m[0][2] = left.z;
	m[1][0] = true_up.x;
	m[1][1] = true_up.y;
	m[1][2] = true_up.z;
	m[2][0] = forward.x * -1;
	m[2][1] = forward.y * -1;
	m[2][2] = forward.z * -1;
	tp = tuple((from.x * -1), (from.y * -1), (from.z * -1), 1);
	return (matrix_multi(m, translation(tp)));
}

t_camera2	camera(double hsize, double vsize, double field_of_view)
{
	t_camera2	c;
	double		half_view;
	double		aspect;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_of_view;
	c.transform = identity_matrix();
	half_view = tan(c.field_of_view / 2);
	aspect = c.hsize / c.vsize;
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}


void free_2d_array(double **arr, int size)
{
	int i;
	i = 0;
	while (i  <size)
	{
		free(arr[i]);
		i++;
	}
	//free(arr);
}

t_ray	ray_for_pixel(t_camera2 camera, double x, double y)
{
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_point		p;
	t_tuple		multi1;
	t_tuple		multi2;
	t_point		pixel;
	t_point		origin;
	t_vector	direction;
	double		**invrs;

	xoffset = (x + 0.5) * camera.pixel_size;
	yoffset = (y + 0.5) * camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	p = point(world_x, world_y, -1);
	invrs = inverse(camera.transform, 4);
	multi1 = matrix_multi_tp(invrs, point_tp(p));
	pixel = point(multi1.x, multi1.y, multi1.z);
	multi2 = matrix_multi_tp(invrs, tuple(0, 0, 0, 1));
	origin = point(multi2.x, multi2.y, multi2.z);
	direction = normalize(subtract_points(pixel, origin));
	free_2d_array(invrs, 4);
	return (ray(origin, direction));
}