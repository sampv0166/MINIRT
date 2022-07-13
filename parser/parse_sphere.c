#include "../includes/minirt.h"

void parse_sphere(char **info, t_data *scene_data)
{
    t_list *new;
    t_sphere *sphere;
    char *point_split;

    point_split = ft_split(info[1], ',');
    sphere = malloc (sizeof (t_sphere));
    if (get_2darray_size(info) != 3)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR AMBIENT LIGHTING", scene_data);
    //scene_data->amb_ratio = parse_double(info[1]);
    // scene_data->amb_color = parse_color(info[2], scene_data);



    new = ft_lstnew(sphere);
    ft_lstadd_back(&scene_data->sphere_list, new);
}