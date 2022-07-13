#include "../includes/minirt.h"

void parse_sphere(char **info, t_data *scene_data)
{
    t_list *new;
    t_sphere *sphere;
    char **point_split;
    char **color_split;

    point_split = ft_split(info[1], ',');
    color_split = ft_split(info[3], ',');
    sphere = malloc (sizeof (t_sphere));
    if (get_2darray_size(info) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    sphere->sp_center.x = parse_double(point_split[0]);
    sphere->sp_center.y = parse_double(point_split[1]);
    sphere->sp_center.z = parse_double(point_split[2]);
    
    sphere->diameter = parse_double(info[2]);

    sphere->color.r = parse_double(color_split[0]);
    sphere->color.g = parse_double(color_split[1]);
    sphere->color.b = parse_double(color_split[2]);
    new = ft_lstnew(sphere);
    ft_lstadd_back(&scene_data->sphere_list, new);
}