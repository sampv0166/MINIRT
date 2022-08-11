#include "../includes/minirt.h"

void parse_sphere(char **info, t_data *scene_data)
{
    t_list *new;
    t_sphere *sphere;
    char **point_split;
    char **color_split;
    int i;

    i = 0;
    if (get_2darray_size(info) != 4)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR SPHERE", scene_data);
    
    point_split = ft_split(info[1], ',');
    color_split = ft_split(info[3], ',');
    if (get_2darray_size(point_split) != 3 || get_2darray_size(color_split) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR SPHERE", scene_data);
    sphere = malloc (sizeof (t_sphere));
    while (i < 3)
    {
        if (skip_dot_verify_digits(point_split[i]) || skip_dot_verify_digits(color_split[i]))
            print_error_msg_and_exit("Wrong Input", scene_data);   
        i++;
    }
    sphere->sp_center.x = parse_double(point_split[0]);
    sphere->sp_center.y = parse_double(point_split[1]);
    sphere->sp_center.z = parse_double(point_split[2]);
    parse_color(info[3], scene_data, &sphere->color);

    if (skip_dot_verify_digits(info[2]))
    {
      print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    sphere->radius = parse_double(info[2]);

    new = ft_lstnew(sphere);
    ft_lstadd_back(&scene_data->sphere_list, new);
}