#include "./includes/minirt.h"

int main (int argc, char **argv)
{
    t_data scene_data;

    if (argc != 2)
        print_error_msg_and_exit("NOT ENOUGH ARGUMENTS", &scene_data);    
    parse_scene(argv[1], &scene_data);
    return (0);
}