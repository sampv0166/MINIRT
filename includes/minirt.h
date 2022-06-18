#ifndef MINIRT_H
#define MINIRT_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

typedef struct s_lights
{
    t_vector pos;
    t_color color;
    double  ratio;

}

// main struct
typedef struct s_data
{
    t_list *objects;
    t_list  *cameras;
    t_list  *lights;
}       t_data;

// PARSE FUNCTIONS
void parse_scene();


#endif