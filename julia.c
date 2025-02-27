/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:31:48 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/27 04:56:39 by iabasala         ###   ########.fr       */
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
      return (0XDB7093- iter * 500);
}
void init_julia(t_julia *data)
{
    data->scale = 0.005;
    data->x_offset = 0.0;
    data->y_offset = 0.0;
    data->c_re = -0.7;
    data->c_im = 0.27;
}

void draw_julia(t_julia *data)
{
    int x;
    int y;
    int iter;
     init_julia(data);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img_data = mlx_get_data_addr(data->img, &data->bpp, 
                                      &data->size_line, &data->endian);
    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            double real = (x - WIDTH / 2.0) * data->scale + data->x_offset;
            double imag = (y - HEIGHT / 2.0) * data->scale + data->y_offset;
            iter = calculate_julia(real, imag, data);
            *(int *)(data->img_data + (y * data->size_line) + (x * 4)) = 
                    get_color(iter);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    mlx_destroy_image(data->mlx, data->img);
    data->img = NULL;
    data->img_data = NULL;
}

