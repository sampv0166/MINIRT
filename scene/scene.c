#include "../includes/minirt.h"

// translation
//---------------------------------------
// -z == bring objects closer to the eye
// +z == move objects away from eye

// +x == move objects to the right
// -x == move ojects  to the left

// +y == move objects to up
//--y == move objects down


// z is used to see the otherside
// positive z will show u the backside
// negative z will be our front side
// remebder 5 and 50

t_plane	*plane(void)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	pl->xyz = tuple(0,0,0,0);
	return (pl);
}

t_shape create_shape(char *shape_name)
{
	t_shape shp;
	shp.transform = identity_matrix();
	shp.material = material();
	if (!ft_strncmp(shape_name, "sp", 2))
	{
		shp.shape = sphere();
		shp.shape_name = "sp";
	}
	if (!ft_strncmp(shape_name, "pl", 2))
	{
		shp.shape = plane();
		shp.shape_name = "pl";
	}	
	return (shp);
}

t_world	default_world(t_data *scene_data)
{
	t_world		w;
	int			i;
	int			j;

	j = 0;
	i = 0;
	w.s = malloc (sizeof (t_shape) * scene_data->total_shape_count);
	
	while (i < scene_data->total_sphere_count)
	{
		w.s[i]	= create_shape("sp");
		i++;
	}
	while (j < scene_data->total_plane_count)
	{
		w.s[i] = create_shape("pl");
		i++;
		j++;
	}
	j = 0;	
	while (j < scene_data->total_cylinder_count)
	{
		w.s[i] = create_shape("pl");
		i++;
		j++;
	}
	return (w);
}

//5N6hV5ZM96we7X2

t_intersect	intersect(t_shape s, t_ray r)
{
	//t_ray local_ray;

	s.ray_in_obj_space = transform(r, inverse(s.transform, 4));
	if (!ft_strncmp(s.shape_name, "sp", 2))
		return (local_intersect_sphere(s.ray_in_obj_space));
	else if(!ft_strncmp(s.shape_name, "pl", 2))
		return(local_intersect_plane(s.ray_in_obj_space));
	
	// printf("\nnever here\n");
	//exit(0);
	return (local_intersect_sphere(s.ray_in_obj_space));		
}


t_intersection	*intersect_world(t_world w, t_ray r)
{
	t_intersection	*xs;
	t_intersect		inter1;

	int i;
	int count;
	xs = NULL;
	i = 0;
	count = 0;
	while (i < 7)
	{
		inter1 = intersect(w.s[i], r);
		if (inter1.count > 0)
		{
			if (count == 0)
			{
				xs = malloc (sizeof(t_intersection) * (2));
				xs[0] = intersection(inter1.t[0],w.s[i], count + 2 );
				xs[1] = intersection(inter1.t[1],w.s[i], count + 2 );
				count += 2;
			}
			else
			{
				t_intersection *tmp;
				tmp = malloc (sizeof(t_intersection) * (count + 2));
				int j;
				j = 0;
				while (j < count)
				{
					tmp[j] = xs[j];
					tmp[j].count = count + 2;
					j++;
				}
				j = count ;
				tmp[j++] = intersection(inter1.t[0],w.s[i], count + 2);
				tmp[j++] = intersection(inter1.t[1],w.s[i], count + 2);
				count += 2;
				xs = tmp;
			}
		}
		i++;
	}
	return (xs);
}

t_comps	prepare_computations(t_intersection i, t_ray r)
{
	t_comps	comps;

	comps.t = i.t;
	comps.object = i.object;
	comps.point = position(r, comps.t);
	comps.eyev = negate_vector(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	comps.over_point.x = comps.point.x + comps.normalv.x * EPSILON;
	comps.over_point.y = comps.point.y + comps.normalv.y * EPSILON;
	comps.over_point.z = comps.point.z + comps.normalv.z * EPSILON;
	if (dot(vector_tp(comps.normalv), vector_tp(comps.eyev)) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate_vector(comps.normalv);
	}
	else
		comps.inside = FALSE;
	return (comps);
}

t_color	shade_hit(t_world w, t_comps comps)
{
	t_color	c;
	t_bool	shadowed;
	
	shadowed = is_shadowed(w, comps.over_point);
	c = lighting(comps.object.material, w.l, comps.over_point, comps.eyev, 
	comps.normalv, shadowed);
	return (c);
}

t_color	color_at(t_world w, t_ray r)
{
	t_intersection	*i;
	t_intersection	h;
	t_comps			comps;

	i = intersect_world(w, r);
	h = hit(i);
	printf("\n%f\n", h.t);
	if (h.count == 0)
		return (color(1, 1, 1));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}