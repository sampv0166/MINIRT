#include "../includes/minirt.h"

static void replace_tabs_and_newline(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '\t')
            line[i] = ' ';
        if (line[i] == '\n')
            line[i] = '\0';    
        i++;    
    }
}

static int check_file_name(char *file_name)
{
    int i;
    i = 0;

    while (file_name[i])
    {
        i++;
    }   
    if (i > 3 && file_name[i] == 't' && file_name[i - 1] == 'r' && file_name[i - 2] == '.')
        return (1);
    return (0);        
}

// static int check_for_duplicate_identifier (char **arr)
// {
//     int i;
//     int j;
//     int count;

//     i = 0;
//     j = 0;
//     while (arr[i])
//     {
//         j = 0;
//         count = 0;
//         while (arr[j])
//         {
//             if (arr[i][0] == arr[j][0])
//             {
//                 printf("%c = %c",arr[i][0] , arr[j][0]  );
//                 count++;
//             }
//             j++;
//         }
//         if (count > 1)
//             return (1);
//         i++;
//     }
//     exit(0);
//     return (0);
// }

static void parse_current_line(char *line, t_data *scene_data)
{
    char **info_split;

    info_split = NULL;
    replace_tabs_and_newline(line);
    info_split = ft_split(line, ' ');
    if (ft_strlen(info_split[0]) == 1 && info_split[0][0] == 'A')
    {
        parse_ambient_lighting(info_split, scene_data);
    }
    else if (ft_strlen(info_split[0]) == 1 && info_split[0][0] == 'C')
    {
        parse_camera(info_split,scene_data);
    }
    else if (ft_strlen(info_split[0]) == 1 &&  info_split[0][0] == 'L')
    {
        parse_light(info_split,scene_data);
    }
    else if (ft_strlen(info_split[0]) == 2 && info_split[0][0] == 's' && info_split[0][1] == 'p')
    {
        scene_data->total_shape_count++;
        scene_data->total_sphere_count++;
        parse_sphere(info_split,scene_data);
    }
    else if (ft_strlen(info_split[0]) == 2 && info_split[0][0] == 'p' && info_split[0][1] == 'l')
    {
        scene_data->total_shape_count++;
        scene_data->total_plane_count++;
        parse_plane(info_split,scene_data);
    }
    else if (ft_strlen(info_split[0]) == 2 && info_split[0][0] == 'c' && info_split[0][1] == 'y')
    {
        scene_data->total_shape_count++;
        scene_data->total_cylinder_count++;
        parse_cylinder(info_split,scene_data);   
    }
    else
    {
       print_error_msg_and_exit("Invalid Identifier", scene_data); 
    }
    free_memmory(info_split);                       
}

void parse_scene(char *file_name, t_data *scene_data)
{
    char *line;
    int fd;

    if (check_file_name(file_name))
        print_error_msg_and_exit("FILE EXTENTION IS INCORRECT", scene_data);
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        print_error_msg_and_exit("ERROR OPENING FILE", scene_data);    
    while (1)
    {
        line = get_next_line(fd);
        if (line && *line != '#')
            parse_current_line(line, scene_data);
        else
        {
            free_memmory(&line);    
            break ;
        }
    }
}