#include "../includes/minirt.h"

void parse_ambient_lighting(char **info, t_data *scene_data)
{
    if (scene_data->amb_set == 1)
        print_error_msg_and_exit("AMBIENT LIGHTING ALREADY DECLARED", scene_data);
    if (get_2darray_size(info) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    if (skip_dot_verify_digits(info[1]))
    {
      print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    scene_data->amb_ratio = parse_double(info[1]);
    if (scene_data->amb_ratio < 0 || scene_data->amb_ratio > 1)
    {
        print_error_msg_and_exit("Invalid ambiance ratio", scene_data);
    }
    parse_color(info[2], scene_data, &scene_data->amb_color);
    scene_data->amb_set = 1;
}