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

t_shape create_shape(char *shape_name)
{
	t_shape shp;
	if (!ft_strncmp(shape_name, "sp", 2))
	{
		shp.shape = sphere();
		shp.shape_name = "sp";
	}
	return (shp);
}


t_world	default_world(void)
{
	char *shape_sphere;

	shape_sphere = "sp";
	t_light		light;
	t_point		p;
	t_world		w;

	p = point(-10, 10, -10);
	light = point_light(p, color(1, 1, 1));


	t_shape floor; 
	floor = create_shape(shape_sphere);
	floor.transform = scaling(tuple(10, 0.01, 10, 1));
	floor.material = material();
	floor.material.color = color(1,0.9,0.9);
	floor.material.specular = 0;

	t_shape leftWall;
	leftWall = create_shape(shape_sphere);
	leftWall.transform = translation(tuple(0,0, 5,1));
	leftWall.transform = matrix_multi(leftWall.transform, rotation_y(-PI/4));
	leftWall.transform = matrix_multi(leftWall.transform, rotation_x(PI/ 2));
	leftWall.transform = matrix_multi(leftWall.transform, scaling(tuple(10,0.01,10, 1)));
	leftWall.material = floor.material;


// // 	right_wall ← sphere()
// // right_wall.transform ← translation(0, 0, 5) *
// // rotation_y(π/4) * rotation_x(π/2) *
// // scaling(10, 0.01, 10)
// // right_wall.material ← floor.material


	t_shape rightWall;
	rightWall =  create_shape(shape_sphere);
	rightWall.transform = translation(tuple(0,0, 5,1));
	rightWall.transform = matrix_multi(rightWall.transform, rotation_y(PI/4));
	rightWall.transform = matrix_multi(rightWall.transform, rotation_x(PI/ 2));
	rightWall.transform = matrix_multi(rightWall.transform, scaling(tuple(10,0.01,10, 1)));
	rightWall.material = floor.material;


	t_shape middle;
	middle = create_shape(shape_sphere);
	middle.transform = translation(tuple (-0.5,1,0.5,1));
	middle.material = material();
	middle.material.color = color(0.1,1,0.5);
	middle.material.diffuse = 0.7;
	middle.material.specular = 0.3;

	t_shape right;
	right =  create_shape(shape_sphere);
	right.transform = matrix_multi(translation(tuple (1.5,0.5,-0.5,1)),  scaling(tuple(0.5,0.5,0.5,1)));
	right.material = material();
	right.material.color = color(0.5,1,0.1);
	right.material.diffuse = 0.7;
	right.material.specular = 0.3;

	t_shape left;
	left = create_shape(shape_sphere);
	left.transform = matrix_multi(translation(tuple (-1.5, 0.33, -0.75,1)),  scaling(tuple(0.33, 0.33, 0.33,1)));
	left.material = material();
	left.material.color = color(1, 0.8, 0.1);
	left.material.diffuse = 0.7;
	left.material.specular = 0.3;

	w.l = light;
	w.s[0] = floor;
	w.s[1] = leftWall;
	w.s[2] = rightWall;
	w.s[3] = middle;
	w.s[4] = right;
	w.s[5] = left;

	return (w);
}

// t_intersection **addToInterSections(t_intersect inter, t_intersection **xs, t_shape sp, int *i,int *cnt)
// {
// 	t_intersection *tmp;
// 	tmp = NULL;
// 	if (*i == 0)
// 	{
// 			//printf("\nfffff\n");
// 		tmp = malloc(sizeof(t_intersection) * 2);
// 		tmp[0] = intersection(inter.t[0], sp);
// 		tmp[0].count = *cnt;
// 		tmp[1] = intersection(inter.t[1], sp);
// 		tmp[1].count = *cnt;
// 		*i += 2;
// 		return(&tmp);
// 	}
// 	else
// 	{
// 			//printf("\nssss\n");
// 				///
// 		tmp = malloc(sizeof(t_intersection) * (*i + 2));
// 		int j;
// 		int k;
// 		j = 0;
// 		k = 0;
// 		printf("\ni i == %d\n", *(i));
// 		while (j < *(i))
// 		{
// 			tmp[j] = xs[0][j];
// 			tmp[j].count =  *cnt;
// 			k++;
// 			j++;
// 		}
// 		tmp[(*i)++] = intersection(inter.t[0], sp);
// 		tmp[(*i)].count = *cnt;
// 		tmp[(*i)++] = intersection(inter.t[1], sp);
// 		tmp[(*i)].count = *cnt;
// 		free(*xs);
// 		*xs = NULL;
// 		return(&tmp);	
// 	}
// }

t_intersect	intersect(t_shape s, t_ray r)
{
	//t_ray local_ray;

	s.ray_in_obj_space = transform(r, inverse(s.transform, 4));
	if (!ft_strncmp(s.shape_name, "sp", 2))
		return (local_intersect_sphere(s.ray_in_obj_space));
	// else if(!ft_strncmp(s.shape_name, "pl", 2))
	// 	return(local_intersect_plane(local_ray));
	
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
	while (i < 6)
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