/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:16:58 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 16:03:18 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
//testing
// Debug prints
int zoom_mandelbrot(int button, int x, int y, t_mandelbrot *data)
{
    (void)x;
    (void)y;
    if (button == 4)
        data->scale /= 1.1;
    else if (button == 5)
        data->scale *= 1.1;
    
    draw_mandelbrot(data);
    return 0;
}
/*int zoom_mandelbrot(int button, int x, int y, t_mandelbrot *data)
{
    if (!data || !data->mlx || !data->win)  // Safety check
        return 0;
        
    double mouse_re = data->x_offset + x * data->scale;
    double mouse_im = data->y_offset + y * data->scale;
    
    if (button == 4)
        data->scale /= 0.9;
    else if (button == 5)
        data->scale *= 0.9;
    
    data->x_offset = mouse_re - x * data->scale;
    data->y_offset = mouse_im - y * data->scale;
    
    draw_mandelbrot(data->mlx, data->win, data);
    return 0;
}*/

int zoom_julia(int button, int x, int y, t_julia *data)
{
    if (!data || !data->mlx || !data->win)  // Safety check
        return 0;
        
    // double mouse_re = data->x_offset + x * data->scale;
    // double mouse_im = data->y_offset + y * data->scale;
    (void)x;
    (void)y;
    if (button == 4)
        data->scale /= 1.1;
    else if (button == 5)
        data->scale *= 1.1;
    
    // data->x_offset = mouse_re - x * data->scale;
    // data->y_offset = mouse_im - y * data->scale;
    draw_julia(data);
    return 0;
}
/*int    zoom_julia(int button, int x, int y, t_julia *data)
{
     double mouse_re = data->x_offset + x * data->scale;
    double mouse_im = data->y_offset + y * data->scale;
        // (void)x;
        // (void)y;
        if (button == 4)
            data->scale /= 0.9;
        if(button == 5)
            data->scale *= 0.9;
        data->x_offset = mouse_re - x * data->scale;
        data->y_offset = mouse_im - y * data->scale;
        draw_julia(data);
        return 0;
}
int     zoom_mandelbrot(int button, int x, int y, t_mandelbrot *data)
{
    double mouse_re = data->x_offset + x * data->scale;
    double mouse_im = data->y_offset + y * data->scale;
        // (void)x;
        // (void)y;
        if (button == 4)
            data->scale /= 0.9;
        if(button == 5)
            data->scale *= 0.9;
            
        data->x_offset = mouse_re - x * data->scale;
        data->y_offset = mouse_im - y * data->scale;
    
        draw_mandelbrot(data->mlx, data->win,data);
        return 0;
}*/
