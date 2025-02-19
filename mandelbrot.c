/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/18 18:15:16 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void    draw_mandelbrot(void *mlx, void *win)
{
    int x, y, iter;
    double a, b, temp;
    double real, imag;
    double scale = 4.0 / WIDTH;
    double x_offset = -2.0;
    double y_offset = -2.0;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // from(x,y) to complex number
            real = (x - WIDTH / 2.0) * scale + x_offset;
            imag = (y - HEIGHT / 2.0) * scale + y_offset;

            // Initialize Z = 0
            a = 0;
            b = 0;
            iter = 0;

            while (a * a + b * b <= 4 && iter < MAX_ITER)
            {
                temp = a * a - b * b + real;
                b = 2.0 * a * b + imag;
                a = temp;
                iter++;
            }

                int color;
    if (iter == MAX_ITER)
        color = 0x000000; // Blac
    else
        color = 0xFFFFFF - iter * 500; // Gradient color

            mlx_pixel_put(mlx, win, x, y, color);

            x++;
        }
        y++;
    }
}


