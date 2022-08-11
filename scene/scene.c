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
	return (pl);
}

t_plane	*cylinder(void)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	return (pl);
}

t_shape create_shape(char *shape_name, void *shape,t_data *scene_data)
{
	t_shape shp;
	t_sphere *sp;
	t_plane  *pl;
	t_cy	 *cy;
	
	shp.transform = identity_matrix();
	if (!ft_strncmp(shape_name, "sp", 2))
	{
		sp = (t_sphere *) shape;
		shp.material = material();
		shp.material.ambient = scene_data->amb_ratio;
		shp.material.color.r = sp->color.r/ 255;
		shp.material.color.g = sp->color.g/ 255;
		shp.material.color.b = sp->color.b/ 255;
		shp.material.diffuse = 0.7;
		shp.material.specular = 0.2;
		shp.shape = sphere(shape);
		shp.shape_name = "sp";
		shp.position = sp->sp_center;
		
		set_transform(&shp, scaling(tuple(sp->radius, sp->radius,sp->radius, 1)));
		set_transform(&shp, matrix_multi(shp.transform, translation(tuple(sp->sp_center.x,sp->sp_center.y,sp->sp_center.z,1))));
	}
	if (!ft_strncmp(shape_name, "pl", 2))
	{
		pl = (t_plane *) shape;
		shp.material = material();
		shp.material.ambient = scene_data->amb_ratio;
		shp.material.color.r = pl->color.r/ 255;
		shp.material.color.g = pl->color.g/ 255;
		shp.material.color.b = pl->color.b/ 255;
		shp.material.diffuse = 0.7;
		shp.material.specular = 0.2;
		shp.shape = plane();
		shp.shape_name = "pl";
		shp.position = pl->xyz;
		shp.norm_vector = pl->norm_vec;
		if (pl->norm_vec.x != 0)
			shp.transform = rotation_x(pl->norm_vec.x);
		if (pl->norm_vec.y != 0)
			set_transform(&shp, matrix_multi(shp.transform , rotation_y(pl->norm_vec.y)));
		if (pl->norm_vec.z != 0)
			set_transform(&shp, matrix_multi(shp.transform, rotation_z(pl->norm_vec.z)));
		
		set_transform(&shp, matrix_multi(shp.transform, translation(tuple(pl->xyz.x,pl->xyz.y,pl->xyz.z,1))));
	
	}
	if (!ft_strncmp(shape_name, "cy", 2))
	{
		cy = (t_cy *) shape;
		shp.material = material();
		shp.material.ambient = scene_data->amb_ratio;
		shp.material.color = cy->color;
		shp.shape = cylinder();
		shp.shape_name = "cy";
		shp.norm_vector = cy->norm_vec;

		set_transform(&shp, matrix_multi(rotation_x(cy->norm_vec.x), rotation_y(cy->norm_vec.y)));
		set_transform(&shp, matrix_multi(shp.transform, rotation_z(cy->norm_vec.z)));
		set_transform(&shp, scaling(tuple(cy->diameter, cy->diameter,cy->diameter, 1)));
		set_transform(&shp, matrix_multi(shp.transform, translation(tuple(cy->xyz.x,cy->xyz.y,cy->xyz.z,1))));
	}	
	return (shp);
}

t_world	default_world(t_data *scene_data)
{
	t_world		w;
	int			i;
	int			j;
	t_light light;

	j = 0;
	i = 0;
	//w.l = scene_data->light_src;
	
	light = point_light(scene_data->light_src.pos, (color(scene_data->light_src.ratio,scene_data->light_src.ratio,scene_data->light_src.ratio)) );
	
	w.l = light;
	w.s = malloc (sizeof (t_shape) * scene_data->total_shape_count);
	while (i < scene_data->total_sphere_count)
	{
		w.s[i]	= create_shape("sp",scene_data->sphere_list->content,scene_data);
		scene_data->sphere_list = scene_data->sphere_list->next;
		i++;
	}
	//
	while (j < scene_data->total_plane_count)
	{
		w.s[i] = create_shape("pl",scene_data->plane_list->content,scene_data);
		scene_data->plane_list = scene_data->plane_list->next;
		i++;
		j++;
	}
	j = 0;	
	while (j < scene_data->total_cylinder_count)
	{
		w.s[i] = create_shape("cy", scene_data->cy_list->content,scene_data);
		scene_data->cy_list = scene_data->cy_list->next;
		i++;
		j++;
	}
	return (w);
}

t_intersect	intersect(t_shape s, t_ray r)
{
	//t_ray local_ray;

	s.ray_in_obj_space = transform(r, inverse(s.transform, 4));
	if (!ft_strncmp(s.shape_name, "sp", 2))
		return (local_intersect_sphere(s.ray_in_obj_space));
	else if(!ft_strncmp(s.shape_name, "pl", 2))
		return(local_intersect_plane(s.ray_in_obj_space));
	else if (!ft_strncmp(s.shape_name, "cy",2))
		return(local_intersect_cylinder(s.ray_in_obj_space));
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
	while (i < w.shape_count)
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
				free(xs);
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
	//printf("\n%f\n", h.t);
	if (h.count == 0)
		return (color(1, 1, 1));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}