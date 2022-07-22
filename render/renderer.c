#include "../includes/minirt.h"

void setup_scene(t_data *scene_data)
{
    scene_data->width = 1080;
    scene_data->height = 720;

    scene_data->aspect_ratio = (double) (scene_data->width) / (scene_data->height);
    scene_data->x0 = -1.0;
    scene_data->x1 = +1.0;

    scene_data->y0 = -1.0;
    scene_data->y1 = +1.0;

    scene_data->xstep = (scene_data->x1 - scene_data->x0) / (scene_data->width - 1);
    scene_data->ystep = (scene_data->y1 - scene_data->y0) / (scene_data->height - 1);
}

