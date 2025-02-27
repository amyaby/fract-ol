/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/27 13:08:15 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int calculate_mandelbrot(double real, double imag)
{
    double a = 0;
    double b = 0;
    double temp;
    int iter = 0;

    while (a * a + b * b <= 4 && iter < MAX_ITER)
    {
        temp = a * a - b * b + real;
        b = 2.0 * a * b + imag;
        a = temp;
        iter++;
    }
    return (iter);
}

static int get_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000);
    return (0xFFFFFF - iter * 500);
}

void draw_mandelbrot(void *mlx, void *win, t_mandelbrot *mandelbrot)
{
    void *img;
    char *data;
    int bpp;
    int sl;
    int endian;
    int x;
    int y;
    int iter;

    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    data = mlx_get_data_addr(img, &bpp, &sl, &endian);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            mandelbrot->real = (x - WIDTH / 2.0) * mandelbrot->scale + mandelbrot->x_offset;
            mandelbrot->imag = (y - HEIGHT / 2.0) * mandelbrot->scale + mandelbrot->y_offset;
            iter = calculate_mandelbrot(mandelbrot->real, mandelbrot->imag);
            *(int *)(data + (y * sl) + (x * 4)) = get_color(iter);
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_destroy_image(mlx, img);
}
