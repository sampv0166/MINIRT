#include "./includes/minirt.h"

// void print_parsed_values(t_data *scene_data)
// {
// 	printf("\nAMBIENCE RATIO\n");
//     printf("%f\n", scene_data->amb_ratio);
// 	printf("\nAMBIENCE COLOR\n");
//     printf("%f\n", scene_data->amb_color.r);
//     printf("%f\n", scene_data->amb_color.g);
//     printf("%f\n", scene_data->amb_color.b);
// 	printf("---------------------------------");

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
    scene_data->img.img_ptr = mlx_new_image(scene_data->mlx.mlx_ptr, 1080, 720);
    scene_data->img.data = (unsigned char*)mlx_get_data_addr(scene_data->img.img_ptr, \
                        &(scene_data->img.bits_per_pixel), &(scene_data->img.size_line), \
                        &(scene_data->img.endian));
    scene_data->mlx.win_ptr = mlx_new_window(scene_data->mlx.mlx_ptr, 1080, 720, "minirt");                       
}



unsigned int perpixel(t_tuple coord)
{
    t_tuple origin;

    origin.x = 0.0;
    origin.y = 0.0;
    origin.z = 2.0;

    t_tuple direction;

    direction.x = coord.x;
    direction.y = coord.y;
    direction.z = -1.0;

    double radius = 0.5;

    double a;
    double b;
    double c;

    a = dot_product(&direction, &direction);
    b = 2.0 * dot_product(&origin, & direction);;
    c = dot_product(&origin, &origin) - radius * radius;
    
    double disc;

    disc = b * b - 4.0 * a * c ;

    /// printf ("dis = %f\n", disc);

    if (disc >= 0.0)
		return 234242342;

	return 0;

}

int main (int argc, char **argv)
{
    t_data scene_data;
    setup_mlx(&scene_data);

	// t_ray r;
    // t_point p;
    // t_vector v;

	// v.x = 0;
	// v.y = 0;
	// v.z = 1;

    // p.x = 0;
    // p.y = 0;
    // p.z = -5;
    // r.origin =  &p;
    // r.direction = &v;
	t_sphere sp;
	// sp.sp_center.x = 0;
	// sp.sp_center.y = 0;
	// sp.sp_center.z = 0;
	// t_intersect  inter;
    // t_intersection1 *ret;

	// ret = intersect(&sp, &r, &inter);
	// printf("count = %d\n", inter.count);
	// printf("inter 1 = %lf\n inter 2 = %lf", inter.value[0], inter.value[1]);

    
    // // t_intersection in1;
    // // t_intersection in2;
    // // printf("\n%f\n", in1.t); 
    // // ret =  intersections(2,&in1, &in2);
    // printf("\n%f\n", ret->ins[0]->t);
    //  printf("\n%f\n", ret->ins[1]->t);

    // t_intersection *ttt;
    // ttt = hit(ret);
    // printf("\n end = %f\n",ttt->t);

//     And i1 ← intersection(5, s)
// And i2 ← intersection(7, s)
// And i3 ← intersection(-3, s)
// And i4 ← intersection(2, s)
// And xs ← intersections(i1, i


    t_intersection *tt11;
    t_intersection *tt22;
    t_intersection *tt33;
    t_intersection *tt44;

    t_intersection1 *ret1;

    tt11 = intersection(5, &sp);
    tt22 = intersection(7, &sp);
    tt33 = intersection(-3, &sp);
    tt44 = intersection(2, &sp);

    ret1 = intersections(4, tt11, tt22, tt33, tt44);

    t_intersection *rrr;

    rrr = hit(ret1);
    if (rrr)
        printf("\n end2 = %f\n",rrr->t);


    // // int color;  
    // t_tuple coord;
    // int w;
   // int h;
    // w = 0;
    // h = 0;
    // unsigned char	*dst;


    // while (h < HEIGHT)
    // {   
    //     w = 0;
    //     while(w < WIDTH)
    //     {

   
    // if (argc != 2)
    //     print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);  
    
    // while (h < 720)
	// {
    //     w = 0;
	// 	while (w < 1080)
	// 	{
    //         coord.x = (double) w / 1080;
    //         coord.y = (double) h / 720;
            
    //         coord.x = coord.x * 2.0 - 1.0;
    //         coord.y = coord.y * 2.0 - 1.0;

    //         dst =  scene_data.img.data + (h * scene_data.img.size_line +
    //         w * (scene_data.img.bits_per_pixel / 8));
	// 		*(unsigned int*)dst  = perpixel(coord);
    //         w++;
	// 	}
    //     h++;

    // }
           
    scene_data.mlx.win_ptr = mlx_new_window(scene_data.mlx.mlx_ptr, WIDTH, HEIGHT, "minirt");     
    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    

	//}


    parse_scene(argv[1], &scene_data);

    // t_tuple origin;
    // t_tuple direction;

    // origin.x = 0.0f;
    // origin.y = 0.0f;
    // origin.z = 2.0f;
    // while (h < 720)
    // {  
    //     w = 0;
    //     while(w < 1080)
    //     {
    //         // a = ray origin 
    //         // b = ray direction
    //         // r = radius
    //         // t = hit distance
    //         color = 0;
    //         coord.x = (double) w / 1080;
    //         coord.y = (double) h / 720;
    //         coord.x = coord.x * 2.0f - 1.0f;
    //         coord.y = coord.y * 2.0f - 1.0f;
    //         coord.z = -1.0f;
    //         direction.x = coord.x;
    //         direction.y = coord.y;
    //         direction.z = -1.0f;
    //         double a = dot_product(&origin, &direction);
	//         double b = 2.0f * dot_product(&origin, &direction);
	//         double c = dot_product(&origin, &direction)- 0.5f * 0.5f;
    //         dst =  scene_data.img.data + (h * scene_data.img.size_line +
    //         w * (scene_data.img.bits_per_pixel / 8));
    //         w++;
    //         printf("a = %f", a);
    //         double disc =  b * b - 4.0f * a * c;
    //         if (disc >= 0.0f)
    //         {
    //             coord.y = coord.y * 255;
    //             coord.x = coord.x * 255;
    //             color = 234242342 ;
    //         }            
	//         *(unsigned int*)dst = color;   
    //     }
    //     h++;
    // }
    //render_scene(&scene_data);
    // ! uncomment this to check all the parsed values
	//print_parsed_values(&scene_data);
     
    mlx_put_image_to_window(scene_data.mlx.mlx_ptr, scene_data.mlx.win_ptr, scene_data.img.img_ptr, 0, 0);                 
    mlx_loop(scene_data.mlx.mlx_ptr);  
    return (0);
}