#include "../includes/minirt.h"



void parse_cylinder(char **info, t_data *scene_data)
{
    t_list *new;
    t_cy *cy;
    char **point_split;
    char **color_split;
    char **norm_vec;
    int i;
    i = 0 ;
    if (get_2darray_size(info) != 6)
    {
        print_error_msg_and_exit("invalid input", scene_data);
    }
    point_split = ft_split(info[1], ',');
    norm_vec = ft_split(info[2], ',');
    color_split = ft_split(info[5], ',');
    
    if (get_2darray_size(point_split) != 3 || get_2darray_size(norm_vec) != 3 || get_2darray_size(color_split) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR PLANE", scene_data);
    while (i < 3)
    {
        if (skip_dot_verify_digits(point_split[i]) || skip_dot_verify_digits(norm_vec[i]) ||
         skip_dot_verify_digits(color_split[i]))
            {
                print_error_msg_and_exit("Wrong Input", scene_data);  
            }
        i++;    
    }
    cy = malloc (sizeof (t_cy));
    
    cy->xyz.x = parse_double(point_split[0]);
    cy->xyz.y = parse_double(point_split[1]);
    cy->xyz.z = parse_double(point_split[2]);
    
    cy->norm_vec.x = parse_double(norm_vec[0]);
    cy->norm_vec.y = parse_double(norm_vec[1]);
    cy->norm_vec.z = parse_double(norm_vec[2]);

    parse_color(info[5], scene_data, &cy->color);
    if (skip_dot_verify_digits(info[3]) || skip_dot_verify_digits(info[4]))
    {
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    cy->diameter = parse_double(info[3]);
    cy->height = parse_double(info[4]);
    new = ft_lstnew(cy);
    ft_lstadd_back(&scene_data->cy_list, new);
}