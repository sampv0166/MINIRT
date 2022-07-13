#include "../includes/minirt.h"



void parse_light(char **info, t_data *scene_data)
{
    char **point_split;
    char **color_split;

    point_split = ft_split(info[1], ',');
    color_split = ft_split(info[3], ',');
    if (get_2darray_size(point_split) != 3 || get_2darray_size(color_split) != 3 )
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    
    scene_data->light_src.pos.x = parse_double(point_split[0]);
    scene_data->light_src.pos.y = parse_double(point_split[1]);
    scene_data->light_src.pos.z = parse_double(point_split[2]);

    scene_data->light_src.ratio = parse_double(info[2]);

    scene_data->light_src.color.r = parse_double(color_split[0]);
    scene_data->light_src.color.g = parse_double(color_split[1]);
    scene_data->light_src.color.b = parse_double(color_split[2]);

}