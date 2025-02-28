/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:16:58 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 20:55:36 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


int handle_key(int keycode, t_julia *data)
{
    if (keycode == 65307)
    close_window(data);

    return (0);
}
int close_window(t_julia *data)
{
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    exit(0);
    return (0);
}

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

int zoom_julia(int button, int x, int y, t_julia *data)
{
    if (!data || !data->mlx || !data->win)  // Safety check
        return 0;
        
    (void)x;
    (void)y;
    if (button == 4)
        data->scale /= 1.1;
    else if (button == 5)
        data->scale *= 1.1;
    draw_julia(data);
    return 0;
}

