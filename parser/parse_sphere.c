#include "../includes/minirt.h"

static int verify_digits( char **pnt_split, char **color_split ,char **info)
{
    int i;

    i = 0;
    while (i < 3)
    {
        if (skip_dot_verify_digits(pnt_split[i]) || skip_dot_verify_digits(color_split[i]) )
            return (0);
        i++;
    }
    if (skip_dot_verify_digits(info[2]))
        return (0); 
    return(1);
}

void parse_sphere(char **info, t_data *scene_data)
{
    t_list *new;
    t_sphere *sphere;
    char **point_split;
    char **color_split;

    if (get_2darray_size(info) != 4)
        print_error_msg_and_exit("INVALID NUMBER OF VALUES FOR SPHERE", scene_data);
    
    point_split = ft_split(info[1], ',');
    color_split = ft_split(info[3], ',');
    if (get_2darray_size(point_split) == 3 && get_2darray_size(color_split) == 3
        && verify_digits(point_split ,color_split, info) )
    {
        sphere = malloc (sizeof (t_sphere));
        sphere->sp_center.x = parse_double(point_split[0]);
        sphere->sp_center.y = parse_double(point_split[1]);
        sphere->sp_center.z = parse_double(point_split[2]);
        
        sphere->radius = parse_double(info[2]);
        
        parse_color(info[3], scene_data, &sphere->color);

        new = ft_lstnew(sphere);
        ft_lstadd_back(&scene_data->sphere_list, new);
    }
    else
    {
        free_2d_char_array(point_split);
        free_2d_char_array(color_split);
        print_error_msg_and_exit("Wrong Input", scene_data);  
    }
    free_2d_char_array(point_split);
    free_2d_char_array(color_split);
}