#include "../includes/minirt.h"

void parse_plane(char **info, t_data *scene_data)
{
    t_list *new;
    t_plane *plane;
    char **point_split;
    char **color_split;
    char **norm_vec;

    point_split = ft_split(info[1], ',');
    norm_vec = ft_split(info[2], ',');
    color_split = ft_split(info[3], ',');
    
    plane = malloc (sizeof (t_plane));
    if (get_2darray_size(info) != 4)
    {
        printf("here = %d",get_2darray_size(info)  );
        print_error_msg_and_exit("INVALID NUMBER OF ", scene_data);
    }
    plane->xyz.x = parse_double(point_split[0]);
    plane->xyz.y = parse_double(point_split[1]);
    plane->xyz.z = parse_double(point_split[2]);
    
    plane->norm_vec.x = parse_double(norm_vec[0]);
    plane->norm_vec.y = parse_double(norm_vec[1]);
    plane->norm_vec.z = parse_double(norm_vec[2]);

    plane->color.r = parse_double(color_split[0]);
    plane->color.g = parse_double(color_split[1]);
    plane->color.b = parse_double(color_split[2]);
    new = ft_lstnew(plane);
    ft_lstadd_back(&scene_data->plane_list, new);
}