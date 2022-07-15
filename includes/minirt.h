#ifndef MINIRT_H
#define MINIRT_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "../libs/libft/libft.h"
#include "../libs/mlx_linux/mlx.h"
#define EPSILON 0.00001


//tuple

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

//point

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

//vector

typedef struct s_vector
{
    double x;
    double y;
    double z;
}              t_vector;

//ray

typedef struct s_ray
{
	t_point		origin;
	t_tuple	direction;
	float		tmin;
	float		tmax;		
}	t_ray;

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
    t_tuple pos;
    t_color color;
    double  ratio;

}               t_light;

// camera information

typedef struct s_camera
{
    t_tuple pos;
    t_tuple norm_vector;
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
	t_tuple sp_center;
    double diameter;
    t_color color;

}		       t_sphere;

typedef struct s_plane
{
	t_tuple xyz;
    t_tuple norm_vec;
    t_color color;
}		       t_plane;

typedef struct s_cy
{
	t_tuple xyz;
    t_tuple norm_vec;
    t_color color;

    double diameter;
    double height;
}		       t_cy;

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

    //light
    t_light light_src;

    //sphere
    t_list *sphere_list;

    //plane
    t_list *plane_list;

    //cy
    t_list *cy_list;
    
    //AMBIENCE
    t_color amb_color;
    double  amb_ratio;
    int     amb_set;

    // screen info
    int width;
    int height;
    double aspect_ratio;
    double x0;
    double x1;

    double y0;
    double y1;

    double xstep;
    double ystep;
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

// RENDER FUNCTIONS
void render_scene(t_data *scene_data);

// ERROR FUNCTIONS
void print_error_msg_and_exit(char *error_msg, t_data *scene_data);

//UTILS
int get_2darray_size(char **arr);
double parse_double(char *str);
void parse_color(char *str, t_data *scene_data, t_color *colors);

// tupple
t_tuple	*point(t_point *dot);
double	dot_product(t_tuple *a, t_tuple *b);

//vector operations
t_point	*subtract_vector(t_point *p, t_vector *vec);

#endif