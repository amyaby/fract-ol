/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:31:48 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/25 00:55:58 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


static int calculate_julia(double real, double imag, t_julia *data)
{
    double a = real;
    double b = imag;
    double temp;
    int iter = 0;

    while (a * a + b * b <= 4 && iter < MAX_ITER)
    {
        temp = a * a - b * b + data->c_re;
        b = 2.0 * a * b + data->c_im;
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

void draw_julia(t_julia *data)
{
    void *img;
    char *img_data;
    int bpp;
    int sl;
    int endian;
    int x;
    int y;
    int iter;

    img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    img_data = mlx_get_data_addr(img, &bpp, &sl, &endian);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            double real = (x - WIDTH / 2.0) * data->scale + data->x_offset;
            double imag = (y - HEIGHT / 2.0) * data->scale + data->y_offset;
            iter = calculate_julia(real, imag, data);
            *(int *)(img_data + (y * sl) + (x * 4)) = get_color(iter);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
    mlx_destroy_image(data->mlx, img);
}