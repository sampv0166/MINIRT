#include "../includes/minirt.h"


void write_pixel(unsigned char *dst, double w, double h, t_color color,t_data *scene_data)
{
    int rr;
    int gg;
    int bb;
    int color_code ;
    
    rr = color.r * 255;
    gg = color.g * 255;
    bb = color.b * 255;

    color_code = rr << 16 | gg << 8 | bb;

    dst =  scene_data->img.data + (int)(h * scene_data->img.size_line +
    w * (scene_data->img.bits_per_pixel / 8));  

    	//     printf("\nr == %f\n", col.r);
    // printf("\ng == %f\n", col.g);
    //printf("\nb == %d\n", color_code);
    
    *(unsigned int*)dst  = color_code;
}

void render(t_camera2 cam, t_world wrld, t_data *scene_data)
{
    double w;
    double h;
    t_ray r;
    t_color color;
    unsigned char	*dst;
    dst = NULL;
    h = 0; 
    w = 0;
    while (h < HEIGHT - 1)
    {
        w = 0;
        while(w < WIDTH - 1)
        {
            r = ray_for_pixel(cam, w, h);
            
            color = color_at(wrld, r);;
        
            write_pixel(dst,w, h, color, scene_data);
            w++;
        }
        h++;
    }

printf("\nend\n");   
}

