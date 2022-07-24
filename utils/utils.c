#include "../includes/minirt.h"

int get_2darray_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;  
    return (i);    
}

static double get_decimal_point(double res, char *str)
{
    double num;
    double divider;
    double dec_val;

    dec_val = 0.0;
    num = 0.0;
    divider = 10;
    while (*str && ft_isdigit(*str))
    {
        dec_val = *str - '0';
        num = num + dec_val / divider; 
        divider = divider * 10;
        str++;
    }
    return (res + num);
}

double parse_double(char *str)
{
    double res;
    int sign;

    res = (double) atoi(str);
    
    sign = 1;
    if (res < 0  || *str == '-')
    {
        str++;
        sign = -1;
    }
    while (ft_isdigit(*str))
        str++;
    if (*str != '.')
        return (res);
    str++;
    return (get_decimal_point(res, str) * sign);
}

int is_str_not_digit(char *str)
{
    int i;

    i = 0;
    while (str[i]) 
    {
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}

t_color parsed_color(double red, double green, double blue)
{
    t_color res;

    res.r = red;
    res.g = green;
    res.b = blue;
    return (res);
}

void parse_color(char *str, t_data *scene_data, t_color *colors)
{
    char **rgb;
    double c[3];

    rgb = ft_split(str, ',');
    if (get_2darray_size(rgb) != 3)
        print_error_msg_and_exit("INVALID COLOR VALUES", scene_data);
    if (is_str_not_digit(rgb[0]) || is_str_not_digit(rgb[1]) || is_str_not_digit(rgb[1])){
        print_error_msg_and_exit("INVALID COLOR VALUES", scene_data);
    }
    c[0] = parse_double(rgb[0]);
    c[1] = parse_double(rgb[1]);
    c[2] = parse_double(rgb[2]);
    if ((c[0] > 255 || c[0] < 0) ||
        (c[1] > 255 || c[1] < 0) ||
        (c[2] > 255 || c[2] < 0))
    {
            print_error_msg_and_exit("INVALID COLOR VALUES", scene_data);
    }
    free_memmory(rgb);
    colors->r = c[0];
    colors->g = c[1];
    colors->b =  c [2];
}

void print_tuple_sam(char *str, t_tuple *tp)
{
    printf("%s",str);
    printf("tp x = %f\n", tp->x);
    printf("tp y = %f\n", tp->y);
    printf("tp z = %f\n", tp->z);
    printf("tp w = %f\n", tp->w);
}
void print_point(char *str,t_point *tp)
{
    printf("%s",str);
    printf("point x = %f\n", tp->x);
    printf("point y = %f\n", tp->y);
    printf("point z = %f\n", tp->z);
}
void print_vector(char *str,t_vector *tp)
{
    printf("%s",str);
    printf("vec x = %f\n", tp->x);
    printf("vec y = %f\n", tp->y);
    printf("vec z = %f\n", tp->z);
}


