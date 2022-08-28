#include "../includes/minirt.h"


static int verify_digits(char **nrm_vec_split, char **pnt_split, char **color_split )
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (skip_dot_verify_digits(nrm_vec_split[i]) || skip_dot_verify_digits(pnt_split[i]) || skip_dot_verify_digits(color_split[i]) )
            return (0);
        i++;
    }  
    return(1);
}

static void store_in_scene_data(t_data *scene_data, char **point_split, char **norm_vec, char **info)
{
    t_list *new;
    t_plane *plane;
    plane = malloc (sizeof (t_plane));
    plane->xyz.x = parse_double(point_split[0]);
    plane->xyz.y = parse_double(point_split[1]);
    plane->xyz.z = parse_double(point_split[2]);

    plane->norm_vec.x = parse_double(norm_vec[0]);
    plane->norm_vec.y = parse_double(norm_vec[1]);
    plane->norm_vec.z = parse_double(norm_vec[2]);

    parse_color(info[3], scene_data, &plane->color);
    new = ft_lstnew(plane);
    ft_lstadd_back(&scene_data->plane_list, new);
}

void parse_plane(char **info, t_data *scene_data)
{
    char **point_split;
    char **color_split;
    char **norm_vec;
    if (get_2darray_size(info) != 4)
    {
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    point_split = ft_split(info[1], ',');
    norm_vec = ft_split(info[2], ',');
    color_split = ft_split(info[3], ',');
    if (get_2darray_size(point_split) == 3 && get_2darray_size(norm_vec) == 3 &&
        get_2darray_size(color_split) == 3 && verify_digits(norm_vec,point_split,color_split))
    {
        store_in_scene_data(scene_data, point_split, norm_vec, info);
    }
    else
    {
        free_2d_char_array(point_split);
        free_2d_char_array(norm_vec);
        free_2d_char_array(color_split);
        print_error_msg_and_exit("Wrong Input", scene_data);    
    }
    free_2d_char_array(point_split);
    free_2d_char_array(norm_vec);
    free_2d_char_array(color_split);
}