#include "./includes/minirt.h"
// !remove this later
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
    t_data scene_data;
    t_world w;
    t_camera2 c;
    t_point		from;
	t_point		to;
    t_vector	up;
    
    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    
    init_scence_data(&scene_data);
    parse_scene(argv[1], &scene_data);
    // !UNCOMMMENT THIS AFTER
    setup_mlx(&scene_data);
    w = default_world(&scene_data);
    //exit(0);
    w.shape_count = scene_data.total_shape_count;
    c = camera(HEIGHT, WIDTH , (scene_data.camera.fov * (PI/180)));
	from = scene_data.camera.pos;
	to = point(0,3,-7);
    up = scene_data.camera.norm_vector;
    c.transform = view_transform(from, to, up);
    c.transform = inverse(c.transform, 4);
    render(c, w, &scene_data);
    // ! uncomment this to check all the parsed values
	//print_parsed_values(&scene_data);
    mlx_put_image_to_window(scene_data.mlx.mlx_ptr, scene_data.mlx.win_ptr, scene_data.img.img_ptr, 0, 0);                 
    mlx_loop(scene_data.mlx.mlx_ptr);  
}   

