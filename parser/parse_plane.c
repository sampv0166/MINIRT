#include "../includes/minirt.h"

void parse_plane(char **info, t_data *scene_data)
{
    t_list *new;
    t_plane *plane;
    char **point_split;
    char **color_split;
    char **norm_vec;
    int  i; 
    i  = 0;
    if (get_2darray_size(info) != 4)
    {
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    point_split = ft_split(info[1], ',');
    norm_vec = ft_split(info[2], ',');
    color_split = ft_split(info[3], ',');
    if (get_2darray_size(point_split) != 3 || get_2darray_size(norm_vec) != 3 || get_2darray_size(color_split) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR PLANE", scene_data);

    plane = malloc (sizeof (t_plane));
    if (get_2darray_size(info) != 4)
    {
        printf("here = %d",get_2darray_size(info)  );
        print_error_msg_and_exit("INVALID NUMBER OF ", scene_data);
    }
    while (i < 3)
    {
        if (skip_dot_verify_digits(point_split[i]) || skip_dot_verify_digits(norm_vec[i]) ||
         skip_dot_verify_digits(color_split[i]))
            {
                print_error_msg_and_exit("Wrong Input", scene_data);  
            }
        i++;    
    }
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