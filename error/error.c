#include "../includes/minirt.h"

void print_error_msg_and_exit(char *error_msg, t_data *scene_data)
{
    ft_putstr_fd("Error\n", 1);
    ft_putstr_fd(error_msg, 1);
    ft_putstr_fd("\n", 1);
    if (scene_data)
        free_scene_data();
    exit(1);    
}