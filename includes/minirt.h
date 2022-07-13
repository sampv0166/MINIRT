#ifndef MINIRT_H
#define MINIRT_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libs/libft/libft.h"
#include "../libs/mlx_linux/mlx.h"

//vector

typedef struct s_vector
{
    double x;
    double y;
    double z;
}              t_vector;


//color

typedef struct s_color
{
    double r;
    double g;
    double b;

}               t_color;

// lights information

typedef struct s_light
{
    t_vector pos;
    t_color color;
    double  ratio;

}               t_light;

// camera information

typedef struct s_camera
{
    t_vector pos;
    t_vector norm_vector;
    double fov;

}               t_camera;


typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_img
{
	void			*img_ptr;
 	int				bits_per_pixel;
	int				size_line;
	int				endian;
	unsigned char	*data;
}					t_img;


// typedef struct s_sphere
// {
//     t_list *sphere;    
//     t_vector sphere_center;
//     double diameter;
//     t_color color;

// }   t_sphere

typedef struct s_sphere
{
	t_vector sp_center;
    double diameter;
    t_color color;

}		       t_sphere;

typedef struct s_plane
{
	t_vector xyz;
    t_vector norm_vec;
    t_color color;
}		       t_plane;

typedef struct sobj_list
{
	void		*content;
	struct obj_list	*next;
}		tobj_list;

// main struct
typedef struct s_data
{
    //mlx
    t_mlx		mlx;

    t_img		img;

    //CAMERA
    t_camera camera;

    // light
    t_light light_src;

    //sphere
    t_list *sphere_list;

    //plane
    t_list *plane_list;

    //AMBIENCE
    t_color amb_color;
    double  amb_ratio;
    int     amb_set;
}       t_data;

// PARSE FUNCTIONS
void parse_scene();


// getnextline functions
char	*get_next_line(int fd);
char	*free_memmory(char **ptr);
char	*ft_strchr(const char *str, int c);
size_t	get_current_line_size(char *saved_line);

//parser functions
void parse_scene(char *file_name, t_data *data);
void parse_ambient_lighting(char **info, t_data *scene_data);
void parse_camera(char **info, t_data *scene_data);
void parse_light(char **info, t_data *scene_data);
void parse_sphere(char **info, t_data *scene_data);
void parse_plane(char **info, t_data *scene_data);
void parse_cylinder(char **info, t_data *scene_data);

//FREE FUNCTIONS
void free_scene_data();



// ERROR FUNCTIONS
void print_error_msg_and_exit(char *error_msg, t_data *scene_data);

//UTILS
int get_2darray_size(char **arr);
double parse_double(char *str);
void parse_color(char *str, t_data *scene_data, t_color *colors);

#endif