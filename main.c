#include "../includes/minirt.h"

int main (int argc, char **argv)
{
    t_data scene_data;

    if (argc != 2)
        error("NOT ENOUGH ARGUMENTS", &scene_data);    
    parse_scene(argv[1], &scene_data);
    return (0);
}