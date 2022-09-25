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

t_cy	*cylinder(t_cy *c)
{
	t_cy	*cy;

	cy = malloc(sizeof(t_cy));
	cy->height = c->height;
	cy->diameter = c->diameter;
	return (cy);
}

void appply_transformations_to_sphere(t_shape *shp, t_sphere *sp)
{
	double	**translate;
	double	**scale;
	double	**transform;

	translate = translation(tuple(sp->sp_center.x,sp->sp_center.y, sp->sp_center.z, 1));
	scale = scaling(tuple (sp->radius, sp->radius, sp->radius, 1));
	transform = matrix_multi(scale, translate);
	free_2d_array(shp->transform, 4);
	shp->transform = transform;
	// set_transform(&shp, matrix_multi(shp.transform, translation(tuple(sp->sp_center.x,sp->sp_center.y,sp->sp_center.z,1))));
	// set_transform(&shp, scaling(tuple(sp->radius, sp->radius,sp->radius, 1)));
	free_2d_array(translate, 4);
	free_2d_array(scale, 4);
	//free_2d_array(transform, 4);
}

void construct_sphere_with_parsed_values(t_shape *shp, t_data *scene_data,t_sphere *sp)
{
	shp->shape = sp;
	shp->material.ambient = scene_data->amb_ratio;
	shp->material.color.r = sp->color.r/ 255;
	shp->material.color.g = sp->color.g/ 255;
	shp->material.color.b = sp->color.b/ 255;
	shp->material.diffuse = 0.7;
	shp->material.specular = 0.2;
	shp->material.shininess = 200;
	shp->shape_name = "sp";
	shp->position = sp->sp_center;
}


void appply_transformations_to_plane(t_shape *shp, t_plane *pl)
{
	// I DID THE CHAINING TRANSFORRMATION LIKE THIS, IF U HAVE BETTER OPTIONS,
	// PLEASE CHANGE IT.. BECAUSE IT INVLOVES MALLOC I HAD TO FIND A WAY TO FREE 
	// THE MATRICES

	double	**translate;
	double	**transform;
	double  **rotation;
	
	if (pl->norm_vec.x > 0)
	{
		rotation = rotation_x(pl->norm_vec.x);
		transform = matrix_multi(shp->transform, rotation);
		shp->transform = transform;
		free_2d_array(rotation, 4);
		free_2d_array(transform, 4);
		rotation = rotation_y(pl->norm_vec.y);
		transform = matrix_multi(shp->transform, rotation);
		shp->transform = transform;
		free_2d_array(rotation, 4);
		free_2d_array(transform, 4);
		rotation = rotation_z(pl->norm_vec.z);
		transform = matrix_multi(shp->transform, rotation);
		shp->transform = transform;
		free_2d_array(rotation, 4);
		free_2d_array(transform, 4);
		shp->transform = transform;
	}
	
	// if (pl->norm_vec.y > 0)
	// {
	// 	rotation = rotation_y(pl->norm_vec.y);
	// 	transform = matrix_multi(shp->transform, rotation);
	// 	free_2d_array(rotation, 4);
	// 	free_2d_array(shp->transform, 4);
	// 	shp->transform = transform;
	// }

	// if (pl->norm_vec.z > 0)
	// {
	// 	rotation = rotation_z(pl->norm_vec.z);
	// 	transform = matrix_multi(shp->transform, rotation);
	// 	free_2d_array(rotation, 4);
	// 	free_2d_array(shp->transform, 4);
	// 	shp->transform = transform;
	// }

	translate = translation(tuple(pl->xyz.x,pl->xyz.y,pl->xyz.z,1));
	transform = matrix_multi( translate,shp->transform);
	//exit(0);
	free_2d_array(shp->transform, 4);
	shp->transform = transform;
	free_2d_array(translate, 4);
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
		double	**translate;
		double	**scale;
		double	**transform;

		sp = (t_sphere *) shape;
		shp.transform = identity_matrix();
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
		
		translate = translation(tuple( sp->sp_center.x,
		sp->sp_center.y, sp->sp_center.z, 1));
		scale = scaling( tuple (sp->radius, sp->radius, sp->radius, 1));

		transform = matrix_multi(scale, translate);
		shp.transform = transform;
		// set_transform(&shp, matrix_multi(shp.transform, translation(tuple(sp->sp_center.x,sp->sp_center.y,sp->sp_center.z,1))));
		// set_transform(&shp, scaling(tuple(sp->radius, sp->radius,sp->radius, 1)));
	}
	if (!ft_strncmp(shape_name, "pl", 2))
	{
		pl = (t_plane *) shape;
		shp.material = material();
		shp.transform = identity_matrix();
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
		shp.transform = identity_matrix();
		shp.material.ambient = scene_data->amb_ratio;
		shp.material.color.r = cy->color.r / 255;
		shp.material.color.g = cy->color.g / 255;
		shp.material.color.b = cy->color.b / 255;

		// printf("\n%f\n",shp.material.color.r);
		// printf("\n%f\n",shp.material.color.g);
		// printf("\n%f\n",shp.material.color.b);

		shp.material.diffuse = 0.7;
		shp.material.specular = 0.2;
		shp.shape = cylinder(cy);
		//printf("%f", cy->height);
		shp.shape_name = "cy";
		shp.norm_vector = cy->norm_vec;

		if (cy->norm_vec.x != 0)
			shp.transform = rotation_x(cy->norm_vec.x);
		if (cy->norm_vec.y != 0)
			set_transform(&shp, matrix_multi(shp.transform , rotation_y(cy->norm_vec.y)));
		if (cy->norm_vec.z != 0)
			set_transform(&shp, matrix_multi(shp.transform, rotation_z(pl->norm_vec.z)));
		set_transform(&shp, scaling(tuple(cy->diameter,cy->height,1, 1)));
		set_transform(&shp, matrix_multi(shp.transform, translation(tuple(cy->xyz.x,cy->xyz.y,cy->xyz.z,1))));

	}	
	return (shp);
}

int create_all_spheres(t_world *w, t_data *scene_data, int j)
{
	int i;
	t_list *temp;

	i = j;
	while (i < scene_data->total_sphere_count)
	{
		w->s[i]	= create_shape("sp",scene_data->sphere_list->content,scene_data);
		temp = scene_data->sphere_list->next;
		free(scene_data->sphere_list);
		scene_data->sphere_list = temp;
		i++;
	}
	return (i);
}

int create_all_planes(t_world *w, t_data *scene_data, int j)
{
	int i;
	int k;
	t_list *temp;

	i = j;
	k = 0;
	while (k < scene_data->total_plane_count)
	{
		w->s[i] = create_shape("pl",scene_data->plane_list->content,scene_data);
		temp = scene_data->plane_list->next;
		free(scene_data->plane_list);
		scene_data->plane_list = temp;
		i++;
		k++;
	}
	return (i);
}

int create_all_cylinders(t_world *w, t_data *scene_data, int j)
{
	int i;
	int k;
	t_list *temp;

	i = j;
	k = 0;
	while (k < scene_data->total_cylinder_count)
	{
		w->s[i] = create_shape("cy", scene_data->cy_list->content,scene_data);
		temp = scene_data->cy_list->next;
		free(scene_data->cy_list);
		scene_data->cy_list = temp;
		i++;
		k++;
	}
	return (i);
}

t_world	default_world(t_data *scene_data)
{
	t_world		w;
	int			i;
	t_light light;

	i = 0;
	light = point_light(scene_data->light_src.pos, (color(scene_data->light_src.ratio,scene_data->light_src.ratio,scene_data->light_src.ratio)) );
	w.l = light;
	w.s = malloc (sizeof (t_shape) * scene_data->total_shape_count);
	i = create_all_spheres(&w, scene_data, i);
	i = create_all_planes(&w, scene_data, i);
	i = create_all_cylinders(&w, scene_data, i);
	return (w);
}

t_intersect	intersect(t_shape s, t_ray r)
{
	double **invrs;

	invrs = inverse(s.transform, 4);
	s.ray_in_obj_space = transform(r, invrs);
	free_2d_array(invrs, 4);
	if (!ft_strncmp(s.shape_name, "sp", 2))
		return (local_intersect_sphere(s.ray_in_obj_space));
	else if(!ft_strncmp(s.shape_name, "pl", 2))
		return(local_intersect_plane(s.ray_in_obj_space));
	else if (!ft_strncmp(s.shape_name, "cy",2))
		return(local_intersect_cylinder(s.shape ,s.ray_in_obj_space));
	return (local_intersect_sphere(s.ray_in_obj_space));		
}


// return all intersection for the ray
t_list	*intersect_world(t_world w, t_ray r)
{
	t_list *xs;
	
	t_intersect inter;
	t_intersection *intersection1;
	t_intersection *intersection2;
	int i;
	int count;

	i = 0;
	count = 0;
	xs = NULL;
		
	while (i < w.shape_count)
	{
		inter = intersect(w.s[i], r);
		if (inter.count > 0)
		{
			intersection1 = malloc (sizeof (t_intersection));
			intersection2 = malloc (sizeof (t_intersection));

			intersection1->object = w.s[i];
			intersection1->t = inter.t[0];

			intersection2->object = w.s[i];
			intersection2->t = inter.t[1];
			if (i == 0)
			{
				xs = ft_lstnew(intersection1);
				ft_lstadd_back(&xs, ft_lstnew(intersection2));
			}
			else
			{
				ft_lstadd_back(&xs, ft_lstnew(intersection1));
				ft_lstadd_back(&xs, ft_lstnew(intersection2));
			}
			// intersection1 = (t_intersection *) xs->content;
			// printf("\n%f\n",intersection1->t);
			// intersection1 = (t_intersection *) xs->next->content;
			// printf("\n%f\n",intersection1->t);
			// 	printf("\n%f\n",intersection1->t);
			count = count + inter.count;
		}
		i++;
	}

	t_list *lst;
	lst = xs;

	while (lst)
	{
		intersection1 = (t_intersection *) lst->content;
		// printf("%d" , intersection1->count);  
		intersection1->count = count;
		lst = lst->next;
	}
	
	// exit(0);
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
	t_list	*i;
	t_intersection	h;
	t_comps			comps;

	i = intersect_world(w, r);

	 
	h = hit(i);
	if (h.count == 0)
	{
		free(i);
		return (color(0, 0, 0));
	}
	comps = prepare_computations(h, r);
		
	free(i);
	return (shade_hit(w, comps));
}