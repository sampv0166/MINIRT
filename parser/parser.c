#include "../includes/minirt.h"

static void remove_extra_spaces(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\t')
            line[i] = ' ';
        i++;    
    }
}

static int check_file_name(char *file_name)
{
    int i;

    i = 0;

    while (file_name[i + 1])
        i++;
    if (i > 3 && file_name[i] == 't' && file_name[i - 1] == 'r' && file_name[i - 2] == '.')
        return (1);
    return (0);        
}

static int check_for_duplicate_identifier (char **arr)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (arr[i])
    {
        j = 0;
        while (arr[j])
        {
            if (arr[i][0] == arr[j][0])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static void parse_current_line(char *line, t_data *scene_data)
{
    int i;
    char **info_split;

    i =0 ;
    info_split = NULL;
    remove_extra_spaces(line);
    info_split = ft_split(line, ' ');
    if (check_for_duplicate_identifier(info_split))
    {
        print_error_msg_and_exit("DUPLICATE IDENTIFIER", scene_data);
        free_memmory(info_split);
    }
    if (info_split[0][0] == 'A')
        parse_ambient_lighting(scene_data);
    else if (info_split[0][0] == 'C')
        parse_camera(scene_data);
    else if (info_split[0][0] == 'L')
        parse_light(scene_data);
    else if (ft_strlen(info_split[0] == 2) && info_split[0][0] == 's' && info_split[0][1] == 'p')
        parse_sphere(scene_data);
    else if (ft_strlen(info_split[0] == 2) && info_split[0][0] == 'p' && info_split[0][1] == 'l')
        parse_plane(scene_data);
    else if (ft_strlen(info_split[0] == 2) && info_split[0][0] == 'c' && info_split[0][1] == 'y')
        parse_cylinder(scene_data);                          
    free_memmory(info_split);
}

void parse_scene(char *file_name, t_data *scene_data)
{
    char *line;

    if (check_file_name(file_name))
        print_error_msg_and_exit("FILE EXTENTION IS INCORRECT", scene_data);

    int fd;

    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        print_error_msg_and_exit("ERROR OPENING FILE", scene_data);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            free(line);        
            break;
        }
        if (*line != '#')
            parse_current_line(line, scene_data);
        free(line);
        line = NULL;    
    }
}