#include "../includes/minirt.h"

static int verify_digits(char **pnt_split, char **color_split ,char **info, t_data *scene_data)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (skip_dot_verify_digits(color_split[i]) || skip_dot_verify_digits(pnt_split[i]))
            return (0);
        i++;
    }
    if (skip_dot_verify_digits(info[2]))
        return(0); 
    if (scene_data->light_src.ratio < 0 || scene_data->light_src.ratio > 1)
        return (0);     
    
    return(1);
}


// !REDUCE TO 25 LINES  - SAMAD
void parse_light(char **info, t_data *scene_data)
{
    char **point_split;
    char **color_split;

    if (get_2darray_size(info) != 4)
    {
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    point_split = ft_split(info[1], ',');
    color_split = ft_split(info[3], ',');
    scene_data->light_src.ratio = parse_double(info[2]);
    if (get_2darray_size(point_split) == 3 && get_2darray_size(color_split) == 3
        && verify_digits(point_split, color_split, info, scene_data)
    )
    {
        scene_data->light_src.pos.x = parse_double(point_split[0]);
        scene_data->light_src.pos.y = parse_double(point_split[1]);
        scene_data->light_src.pos.z = parse_double(point_split[2]);
        parse_color(info[3], scene_data, &scene_data->light_src.color);
    }
    else
    {
        free_2d_char_array(point_split);
        free_2d_char_array(color_split);
    }
    free_2d_char_array(point_split);
    free_2d_char_array(color_split);
}