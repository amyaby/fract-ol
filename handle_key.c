#include "fractal.h"


int handle_key(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307)
        exit(0);
    return (0);
}
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}
int handle_mouse_julia(int button, int x, int y, t_julia *data)
{
    if (button == 4)
        data->zoom *= 1.1;
    else if (button == 5)
        data->zoom *= 0.9;
     data->x_offset += (x - WIDTH / 2) / (0.5 * data->zoom * WIDTH);
    data->y_offset += (y - HEIGHT / 2) / (0.5 * data->zoom * HEIGHT);
    draw_julia(data);
    return (0);
}
int handle_mouse_mandelbrot(int button, int x, int y, t_mandelbrot *data)
{
    if (button == 4)
        data->zoom *= 1.1;
    else if (button == 5)
        data->zoom *= 0.9;
    data->x_offset += (x - WIDTH / 2) / (0.5 * data->zoom * WIDTH);
    data->y_offset += (y - HEIGHT / 2) / (0.5 * data->zoom * HEIGHT);
    draw_mandelbrot(data->mlx, data->win, data);

    return (0);
}
