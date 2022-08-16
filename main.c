#include "./includes/minirt.h"

void print_parsed_values(t_data *scene_data)
{
	printf("\nAMBIENCE RATIO\n");
    printf("%f\n", scene_data->amb_ratio);
	printf("\nAMBIENCE COLOR\n");
    printf("%f\n", scene_data->amb_color.r);
    printf("%f\n", scene_data->amb_color.g);
    printf("%f\n", scene_data->amb_color.b);
	printf("---------------------------------\n");
    printf("\nCAMERA LOCATION\n");
    printf("%f\n", scene_data->camera.pos.x);
    printf("%f\n",  scene_data->camera.pos.y);
    printf("%f\n",  scene_data->camera.pos.z);
    printf("\nCAMERA NORM VECTOR\n");
    printf("%f\n", scene_data->camera.norm_vector.x);
    printf("%f\n", scene_data->camera.norm_vector.y);
    printf("%f\n", scene_data->camera.norm_vector.z);
	printf("\nCAMERA FOV\n");
    printf("%f\n", scene_data->camera.fov);
	printf("---------------------------------");
    printf("\n LIGHT SOURCE POINT\n");
    printf("%f\n", scene_data->light_src.pos.x);
    printf("%f\n",  scene_data->light_src.pos.y);
    printf("%f\n",  scene_data->light_src.pos.z);
	printf("\nLight COLOR\n");
    printf("%f\n", scene_data->light_src.color.r);
    printf("%f\n", scene_data->light_src.color.r);
    printf("%f\n", scene_data->light_src.color.r);
	printf("\nLIGHT RATIO\n");
    printf("%f\n", scene_data->light_src.ratio);
	printf("---------------------------------");
    while (scene_data->sphere_list)
    {
        t_sphere *sphere = scene_data->sphere_list->content; 
        printf("\n SPHERE CENTER POINT\n");
        printf("%f\n", sphere->sp_center.x);
        printf("%f\n",  sphere->sp_center.y);
        printf("%f\n",  sphere->sp_center.z);
        printf("\nsphere color\n");
        printf("%f\n", sphere->color.r);
        printf("%f\n",  sphere->color.g);
        printf("%f\n",  sphere->color.b);
        printf("\nradiance\n");
        printf("%f\n", sphere->radius);
        scene_data->sphere_list = scene_data->sphere_list->next;
    }
	printf("---------------------------------");
      while (scene_data->plane_list)
    {
        t_plane *plane = scene_data->plane_list->content; 
        printf("\n plane point xyz\n");
        printf("%f\n", plane->xyz.x);
        printf("%f\n",  plane->xyz.y);
        printf("%f\n",  plane->xyz.z);
        printf("\n norm vec\n");
        printf("%f\n", plane->norm_vec.x);
        printf("%f\n",  plane->norm_vec.y);
        printf("%f\n",  plane->norm_vec.z);
        printf("\nplane color\n");
        printf("%f\n", plane->color.r);
        printf("%f\n",  plane->color.g);
        printf("%f\n",  plane->color.b);
        scene_data->plane_list = scene_data->plane_list->next;
    }
	printf("---------------------------------");
    while (scene_data->cy_list)
    {
        t_cy *cy = scene_data->cy_list->content; 
        printf("\n cy point xyz\n");
        printf("%f\n", cy->xyz.x);
        printf("%f\n",  cy->xyz.y);
        printf("%f\n",  cy->xyz.z);
        printf("\n norm vec\n");
        printf("%f\n", cy->norm_vec.x);
        printf("%f\n",  cy->norm_vec.y);
        printf("%f\n",  cy->norm_vec.z);
        printf("\ncy color\n");
        printf("%f\n", cy->color.r);
        printf("%f\n",  cy->color.g);
        printf("%f\n",  cy->color.b);
      printf("\ncy diameter\n");
        printf("%f\n", cy->diameter);
            printf("\ncy height\n");
        printf("%f\n", cy->height);
        scene_data->cy_list = scene_data->cy_list->next;
    }
	printf("---------------------------------");
}

void setup_mlx(t_data *scene_data)
{
    scene_data->mlx.mlx_ptr = malloc(sizeof(*scene_data->mlx.mlx_ptr));
    scene_data->mlx.mlx_ptr = mlx_init();
    scene_data->img.img_ptr = mlx_new_image(scene_data->mlx.mlx_ptr, WIDTH, HEIGHT);
    scene_data->img.data = (unsigned char*)mlx_get_data_addr(scene_data->img.img_ptr, \
                        &(scene_data->img.bits_per_pixel), &(scene_data->img.size_line), \
                        &(scene_data->img.endian));
    scene_data->mlx.win_ptr = mlx_new_window(scene_data->mlx.mlx_ptr,WIDTH, HEIGHT, "minirt");                       
}

// int	rgb_to_int(t_color rgb)
// {
// 	return(rgb.r << 16 | rgb.g << 8 | rgb.b);
// }

void init_scence_data(t_data *scene_data)
{
    scene_data->total_shape_count = 0;
    scene_data->total_sphere_count = 0;
    scene_data->total_plane_count = 0;
    scene_data->total_cylinder_count = 0;
    scene_data->sphere_list = NULL;
    scene_data->plane_list  = NULL;
    scene_data->cy_list = NULL;
}

int main (int argc, char **argv) {


    // // RAY MISSES SPHERE
    // /*Examples:
    // | origin
    // | point(1, 0, 0)
    // | point(0, 0, 0)
    // | point(0, 0, -5)

    // direction
    // |
    // vector(0, 1, 0) |
    // vector(0, 1, 0) |
    // vector(1, 1, 1) | */


    // // RAY HIts SPHERE
    // /*Examples:
    // | origin
    // | point(1, 0, 0)
    // | point(0, 0, 0)
    // | point(0, 0, -5)

    // direction
    // |
    // vector(0, 1, 0) |
    // vector(0, 1, 0) |
    // vector(1, 1, 1) | */

    // t_ray r;
    // t_intersect inter;

    // // tests 1
    // r.origin = point(0, 3, 0);
    // r.direction = vector(0, -1, 0);

    // r.direction =  normalize(r.direction);

    // t_cy cy;

    // inter  =  local_intersect_cylinder( &cy, r);

    // printf("\n%d\n", inter.count);

    // // test 2
    // r.origin = point(0, 3, -2);
    // r.direction = vector(0, -1, 2);

    // r.direction =  normalize(r.direction);


    // inter  =  local_intersect_cylinder( &cy, r);

    // printf("\n%d\n", inter.count);


    // // test 3
    // r.origin = point(0, 4, -2);
    // r.direction = vector(0, -1, 1);

    // r.direction =  normalize(r.direction);


    // inter  =  local_intersect_cylinder( &cy, r);

    // printf("\n%d\n", inter.count);

    // // test 4
    // r.origin = point(0, 0, -2);
    // r.direction = vector(0, 1, 2);

    // r.direction =  normalize(r.direction);


    // inter  =  local_intersect_cylinder( &cy, r);

    // printf("\n%d\n", inter.count);


    // // test 5
    // r.origin = point(0, -1, -2);
    // r.direction = vector(0, 1, 1);

    // r.direction =  normalize(r.direction);


    // inter  =  local_intersect_cylinder( &cy, r);

    // printf("\n%d\n", inter.count);

    // // test 6
    // // r.origin = point(0, 1.5, -2);
    // // r.direction = vector(0, 0, 1);

    // // r.direction =  normalize(r.direction);


    // // inter  =  local_intersect_cylinder(&cy, r);

    // // printf("\n%d\n", inter.count);
    // // t_vector v;
    // // v =  local_normal_at_cylinder(point(-1,1,0));

    // // print_vector("local",&v);
    

    // exit(0);

    t_data scene_data;
    
    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    
    init_scence_data(&scene_data);
    parse_scene(argv[1], &scene_data);
    //     print_parsed_values(&scene_data);
    //    exit(0);
    setup_mlx(&scene_data);

    t_world w;
    t_camera2 c;
    

    w = default_world(&scene_data);
    w.shape_count = scene_data.total_shape_count;
    c = camera(HEIGHT, WIDTH , (scene_data.camera.fov * (PI/180)));
    //  // c = camera(HEIGHT, WIDTH , ((scene_data.camera.fov * 180) /M_PI ));

    // printf("%f\n", scene_data.camera.fov * (PI/180));
	// exit(0);  
    t_point		from;
	t_point		to;
    t_vector	up;


	from = scene_data.camera.pos;

	to = point(0,3,-7);
	
    up = scene_data.camera.norm_vector;

    c.transform = view_transform(from, to, up);
    

    //print_matrix(c.transform, 4);
    c.transform = inverse(c.transform, 4);
  //  print_matrix(c.transform, 4);
    render(c, w, &scene_data);
    
    //printf("here stop");

    //render_scene(&scene_data);
    // ! uncomment this to check all the parsed values
	//print_parsed_values(&scene_data);
    mlx_put_image_to_window(scene_data.mlx.mlx_ptr, scene_data.mlx.win_ptr, scene_data.img.img_ptr, 0, 0);                 
    mlx_loop(scene_data.mlx.mlx_ptr);  
}   

