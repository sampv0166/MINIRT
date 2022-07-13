#include "../includes/minirt.h"



void parse_cylinder(char **info, t_data *scene_data)
{
    t_list *new;
    t_cy *cy;
    char **point_split;
    char **color_split;
    char **norm_vec;

    point_split = ft_split(info[1], ',');
    norm_vec = ft_split(info[2], ',');
    color_split = ft_split(info[5], ',');
    
    cy = malloc (sizeof (t_cy));
    if (get_2darray_size(info) != 5)
    {
        printf("here = %d",get_2darray_size(info)  );
        print_error_msg_and_exit("INVALID NUMBER OF ", scene_data);
    }
    cy->xyz.x = parse_double(point_split[0]);
    cy->xyz.y = parse_double(point_split[1]);
    cy->xyz.z = parse_double(point_split[2]);
    
    cy->norm_vec.x = parse_double(norm_vec[0]);
    cy->norm_vec.y = parse_double(norm_vec[1]);
    cy->norm_vec.z = parse_double(norm_vec[2]);

    cy->color.r = parse_double(color_split[0]);
    cy->color.g = parse_double(color_split[1]);
    cy->color.b = parse_double(color_split[2]);
    cy->diameter = parse_double(info[3]);
    cy->height = parse_double(info[4]);
    new = ft_lstnew(cy);
    ft_lstadd_back(&scene_data->cy_list, new);
}