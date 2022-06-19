#include "../includes/minirt.h"



void parse_plane(char **info, t_data *scene_data)
{

    if (get_2darray_size(info) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    scene_data->amb_ratio = parse_double(info[1]);
    //scene_data->amb_color = parse_color(info[2], scene_data);
}