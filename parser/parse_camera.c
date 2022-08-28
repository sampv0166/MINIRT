#include "../includes/minirt.h"

int verify_digits(char **nrm_vec_split, char **pnt_split, char **info)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (skip_dot_verify_digits(nrm_vec_split[i]) || skip_dot_verify_digits(pnt_split[i]))
            return (0);
        i++;
    }
    if (skip_dot_verify_digits(info[3]))
        return (0);
    return(1);
}

void store_in_scene_data(t_data *scene_data, char **point_split, char **norm_vec_split, char **info)
{
    scene_data->camera.pos.x = parse_double(point_split[0]);
    scene_data->camera.pos.y = parse_double(point_split[1]);
    scene_data->camera.pos.z = parse_double(point_split[2]); 

    scene_data->camera.norm_vector.x = parse_double(norm_vec_split[0]);
    scene_data->camera.norm_vector.y = parse_double(norm_vec_split[1]);
    scene_data->camera.norm_vector.z = parse_double(norm_vec_split[2]);

    scene_data->camera.fov = parse_double(info[3]);
}

void parse_camera(char **info, t_data *scene_data)
{
    char **point_split;
    char **norm_vec_split;

    if (get_2darray_size(info) != 4)
    {
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    point_split = ft_split(info[1], ',');
    norm_vec_split = ft_split(info[2], ',');
    if (get_2darray_size(point_split) == 3 && get_2darray_size(norm_vec_split) == 3 &&
        verify_digits(norm_vec_split, point_split , info))
    {        
        store_in_scene_data(scene_data, point_split, norm_vec_split, info);
    }
    else
    {
        free_2d_char_array(point_split);
        free_2d_char_array(norm_vec_split);
        print_error_msg_and_exit("Wrong Input", scene_data);
    }
    free_2d_char_array(point_split);
    free_2d_char_array(norm_vec_split);
}
