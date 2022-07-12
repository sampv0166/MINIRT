#include "./includes/minirt.h"

void print_parsed_values(t_data *scene_data)
{
	printf("\nAMBIENCE RATIO\n");
    printf("%f\n", scene_data->amb_ratio);
	printf("\nAMBIENCE COLOR\n");
    printf("%f\n", scene_data->amb_color.r);
    printf("%f\n", scene_data->amb_color.g);
    printf("%f\n", scene_data->amb_color.b);
	printf("---------------------------------");
}


int main (int argc, char **argv)
{
    t_data scene_data;

    scene_data.mlx.mlx_ptr= malloc(sizeof(*scene_data.mlx.mlx_ptr));
    scene_data.mlx.mlx_ptr = mlx_init();
    /*scene_data.img->img_ptr = mlx_new_image(scene_data.mlx->mlx_ptr, 1080, 720);
    scene_data.img->data = (unsigned char*)mlx_get_data_addr(scene_data.img->img_ptr, \
                        &(scene_data.img->bits_per_pixel), &(scene_data.img->size_line), \
                        &(scene_data.img->endian));*/
    scene_data.mlx.win_ptr = mlx_new_window(scene_data.mlx.mlx_ptr, 1080, 720, "minirt");     
    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    
    parse_scene(argv[1], &scene_data);
	print_parsed_values(&scene_data);
    // while(1)
    //     ;                   
    mlx_loop(scene_data.mlx.mlx_ptr);  
    return (0);
}