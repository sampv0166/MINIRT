#include "../includes/minirt.h"



void parse_camera(char **info, t_data *scene_data)
{
    char **point_split;
    char **norm_vec_split;

    point_split = ft_split(info[1], ',');
    norm_vec_split = ft_split(info[2], ',');


    if (get_2darray_size(point_split) != 3 || get_2darray_size(norm_vec_split) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    scene_data->camera.pos.x = parse_double(point_split[0]);
    scene_data->camera.pos.y = parse_double(point_split[1]);
    scene_data->camera.pos.z = parse_double(point_split[2]); 

    scene_data->camera.norm_vector.x = parse_double(norm_vec_split[0]);
    scene_data->camera.norm_vector.y = parse_double(norm_vec_split[1]);
    scene_data->camera.norm_vector.z = parse_double(norm_vec_split[2]);
    scene_data->camera.fov = parse_double(info[3]);
}
