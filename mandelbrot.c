/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/19 16:30:07 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void draw_mandelbrot(void *mlx, void *win)
{
    void *img;
    char *data;
    int bits_per_pixel, size_line, endian;
    int x, y, iter;
    double a, b, temp, real, imag;
    double scale = 4.0 / WIDTH;
    double x_offset = -2.0 + 1.25;
    double y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;

    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            real = (x - WIDTH / 2.0) * scale + x_offset;
            imag = (y - HEIGHT / 2.0) * scale + y_offset;
            a = 0; b = 0; iter = 0;
            while (a * a + b * b <= 4 && iter < MAX_ITER)
            {
                temp = a * a - b * b + real;
                b = 2.0 * a * b + imag;
                a = temp;
                iter++;
            }
            int color;
            if (iter == MAX_ITER)
                color = 0x000000;
            else
                color = 0xFFFFFF - iter * 500;
            *(int *)(data + (y * size_line) + (x * 4)) = color;
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_destroy_image(mlx, img);
}


