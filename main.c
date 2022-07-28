#include "./includes/minirt.h"

// void print_parsed_values(t_data *scene_data)
// {
// 	printf("\nAMBIENCE RATIO\n");
//     printf("%f\n", scene_data->amb_ratio);
// 	printf("\nAMBIENCE COLOR\n");
//     printf("%f\n", scene_data->amb_color.r);
//     printf("%f\n", scene_data->amb_color.g);
//     printf("%f\n", scene_data->amb_color.b);
// 	printf("---------------------------------")
//     printf("\nCAMERA LOCATION\n");
//     printf("%f\n", scene_data->camera.pos.x);
//     printf("%f\n",  scene_data->camera.pos.y);
//     printf("%f\n",  scene_data->camera.pos.z);
//     printf("\nCAMERA NORM VECTOR\n");
//     printf("%f\n", scene_data->camera.norm_vector.x);
//     printf("%f\n", scene_data->camera.norm_vector.y);
//     printf("%f\n", scene_data->camera.norm_vector.z);
// 	printf("\nCAMERA FOV\n");
//     printf("%f\n", scene_data->camera.fov);
// 	printf("---------------------------------");
//     printf("\n LIGHT SOURCE POINT\n");
//     printf("%f\n", scene_data->light_src.pos.x);
//     printf("%f\n",  scene_data->light_src.pos.y);
//     printf("%f\n",  scene_data->light_src.pos.z);
//     // printf("\nCAMERA NORM VECTOR\n");
//     // printf("%f\n", scene_data->camera.norm_vector.x);
//     // printf("%f\n", scene_data->camera.norm_vector.y);
//     // printf("%f\n", scene_data->camera.norm_vector.z);
// 	printf("\nLIGHT RATIO\n");
//     printf("%f\n", scene_data->light_src.ratio);
// 	printf("---------------------------------");
//     while (scene_data->sphere_list)
//     {
//         t_sphere *sphere = scene_data->sphere_list->content; 
//         printf("\n SPHERE CENTER POINT\n");
//         printf("%f\n", sphere->sp_center.x);
//         printf("%f\n",  sphere->sp_center.y);
//         printf("%f\n",  sphere->sp_center.z);
//         printf("\nsphere color\n");
//         printf("%f\n", sphere->color.r);
//         printf("%f\n",  sphere->color.g);
//         printf("%f\n",  sphere->color.b);
//         printf("\nradiance\n");
//         printf("%f\n", sphere->diameter);
//         scene_data->sphere_list = scene_data->sphere_list->next;
//     }
// 	printf("---------------------------------");
//       while (scene_data->plane_list)
//     {
//         t_plane *plane = scene_data->plane_list->content; 
//         printf("\n plane point xyz\n");
//         printf("%f\n", plane->xyz.x);
//         printf("%f\n",  plane->xyz.y);
//         printf("%f\n",  plane->xyz.z);
//         printf("\n norm vec\n");
//         printf("%f\n", plane->norm_vec.x);
//         printf("%f\n",  plane->norm_vec.y);
//         printf("%f\n",  plane->norm_vec.z);
//         printf("\nplane color\n");
//         printf("%f\n", plane->color.r);
//         printf("%f\n",  plane->color.g);
//         printf("%f\n",  plane->color.b);
//         scene_data->plane_list = scene_data->plane_list->next;
//     }
// 	printf("---------------------------------");
//     while (scene_data->cy_list)
//     {
//         t_cy *cy = scene_data->cy_list->content; 
//         printf("\n cy point xyz\n");
//         printf("%f\n", cy->xyz.x);
//         printf("%f\n",  cy->xyz.y);
//         printf("%f\n",  cy->xyz.z);
//         printf("\n norm vec\n");
//         printf("%f\n", cy->norm_vec.x);
//         printf("%f\n",  cy->norm_vec.y);
//         printf("%f\n",  cy->norm_vec.z);
//         printf("\ncy color\n");
//         printf("%f\n", cy->color.r);
//         printf("%f\n",  cy->color.g);
//         printf("%f\n",  cy->color.b);
//       printf("\ncy diameter\n");
//         printf("%f\n", cy->diameter);
//             printf("\ncy height\n");
//         printf("%f\n", cy->height);
//         scene_data->cy_list = scene_data->cy_list->next;
//     }
// 	printf("---------------------------------");
// }

void setup_mlx(t_data *scene_data)
{
    scene_data->mlx.mlx_ptr= malloc(sizeof(*scene_data->mlx.mlx_ptr));
    scene_data->mlx.mlx_ptr = mlx_init();
    scene_data->img.img_ptr = mlx_new_image(scene_data->mlx.mlx_ptr, WIDTH, HEIGHT);
    scene_data->img.data = (unsigned char*)mlx_get_data_addr(scene_data->img.img_ptr, \
                        &(scene_data->img.bits_per_pixel), &(scene_data->img.size_line), \
                        &(scene_data->img.endian));
    scene_data->mlx.win_ptr = mlx_new_window(scene_data->mlx.mlx_ptr,WIDTH, HEIGHT, "minirt");                       
}

unsigned int perpixel(t_tuple coord)
{
    t_tuple origin;

    origin.x = 0.0;
    origin.y = 0.0;
    origin.z = -5;

    t_tuple direction;

    direction.x = coord.x;
    direction.y = coord.y;
    direction.z = -1.0;

    double radius = 0.5;

    double a;
    double b;
    double c;

    a = dot(direction, direction);
    b = 2.0 * dot(origin, direction);;
    c = dot(origin, origin) - radius * radius;
    
    double disc;

    disc = b * b - 4.0 * a * c ;

    /// printf ("dis = %f\n", disc);

    if (disc >= 0.0)
		return 234242342;

	return 0;

}

// int	rgb_to_int(t_color rgb)
// {
// 	return(rgb.r << 16 | rgb.g << 8 | rgb.b);
// }


int main (int argc, char **argv)
{
    t_data scene_data;
    setup_mlx(&scene_data);
    int w;
    int h;
    double wall_z = 2;
    double wall_size = 7;
    double canvas_pixels = WIDTH;

    double pixel_size;
    pixel_size = wall_size / canvas_pixels;
    double half;

    half = wall_size / 2;

    w = 0;
    h = 0;
    double world_y;
    double world_x;
    t_point position1;
    t_ray r;

    t_intersect *inter;

    r.origin.x = 0;
    r.origin.y = 0;
    r.origin.z = -5;
     

    t_sphere *sp;
    sp = sphere();
    sp->material = material();

    t_point light_position;
    light_position = point(-10 ,10,-10);
    //int light_color = 16777211;

    t_light light;
    t_color color;
    color.r =  1;
    color.g = 0.2;
    color.b = 1;

    light = point_light(light_position, color);

    unsigned char	*dst;
    while (h < canvas_pixels - 1)
    {   
         w = 0;
        world_y = half - pixel_size * h;
        while(w < canvas_pixels - 1)
        {
            world_x = -half + pixel_size * w;
            position1.x = world_x;
            position1.y = world_y;
            position1.z = wall_z;
            r.direction = normalize(subtract_points(position1, r.origin));
            inter = intersect(sp, &r);

            // point ← position1(ray, hit.t)
            // normal ← normal_at(hit.object, point)
            // eye ← -ray.direction

            t_tuple p;
            t_vector normal;
            t_color col;

            p = position(r, inter->value[0]);
            t_point pnt;
            pnt.x = p.x;
            pnt.y = p.y;
            pnt.z = p.z;

            t_vector eye;

            eye = negate_vector(r.direction);

            normal = normal_at(sp,pnt);
            col = lighting(sp->material, light, pnt, eye , normal);

            // std::cout << "r = " << col.r << "\n";
            // std::cout << "g = " << col.g << "\n";
            // std::cout << "b = " << col.b << "\n";
            
   
            int rr;
            int gg;
            int bb;

            rr = col.r * 255;
            gg = col.g * 255;
            bb = col.b * 255;
            
            // printf("r = %lf\n", rr);
            // printf("g = %lf\n", gg);
            // printf("b = %lf\n", bb);
            // int col;
//             int	rgb_to_int(const t_rgb rgb)
// {
	        //col = rgb.r << 16 | rgb.g << 8 | rgb.b;
// }
            int color_code;

            color_code = rr << 16 | gg << 8 | bb;



            dst =  scene_data.img.data + (h * scene_data.img.size_line +
            w * (scene_data.img.bits_per_pixel / 8));    
            if (inter->count > 0)
			    *(unsigned int*)dst  = color_code;
            else
                *(unsigned int*)dst  = 0;
            w++;

        }
        h++;
    }
    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    
    parse_scene(argv[1], &scene_data);
    //render_scene(&scene_data);
    // ! uncomment this to check all the parsed values
	//print_parsed_values(&scene_data);
    mlx_put_image_to_window(scene_data.mlx.mlx_ptr, scene_data.mlx.win_ptr, scene_data.img.img_ptr, 0, 0);                 
    mlx_loop(scene_data.mlx.mlx_ptr);  
    return (0);
}