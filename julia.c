/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:31:48 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/22 15:04:49 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*static int calculate_julia(double real, double imag, t_julia *data)
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

int julia(int argc, char **argv)
{
    t_julia data;
    (void)argc;
    data.c_re = atodbl(argv[2]);
    data.c_im = atodbl(argv[3]);
    data.scale = 4.0 / WIDTH;
    data.x_offset = 0.0;
    data.y_offset = 0.0;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Julia Set");
    draw_julia(&data);

    mlx_key_hook(data.win, handle_key, &data);
    mlx_loop(data.mlx);
    return (0);
}*/

static int calculate_julia(double real, double imag, t_julia *data)
{
    int iter = 0;
    while (real * real + imag * imag <= 4 && iter < MAX_ITER)
    {
        double temp = real * real - imag * imag + data->c_re;
        imag = 2.0 * real * imag + data->c_im;
        real = temp;
        iter++;
    }
    return (iter);
}

/*static int get_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000); // Black for max iterations
    int color = (int)(255.0 * iter / MAX_ITER);
    return ((color << 16) | (color << 8) | color); // Smooth grayscale gradient
}*/
/*static int get_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000); // Black for max iterations

    int red = (int)(255.0 * iter / MAX_ITER);     // Gradual increase in red
    int blue = 255 - red;                         // Gradual decrease in blue
    int green = 0;                                // Keep green at 0 for purple shades

    return ((red << 16) | (green << 8) | blue);   // Create the purple color
}*/
static int get_color(int iter)
{
    if (iter == MAX_ITER)
        return (0x000000); // Black for max iterations

    int red = (int)(128.0 + 127.0 * iter / MAX_ITER);   // Start with darker red and gradually increase
    int blue = (int)(255.0 - 127.0 * iter / MAX_ITER);  // Start with full blue and gradually decrease
    int green = 0;  // Keep green at 0 for purple hues

    return ((red << 16) | (green << 8) | blue);   // Combine red and blue to create purple shades
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

    img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    img_data = mlx_get_data_addr(img, &bpp, &sl, &endian);

    //printf("c_re = %f, c_im = %f\n", data->c_re, data->c_im);
    //printf("scale = %f, x_offset = %f, y_offset = %f\n", data->scale, data->x_offset, data->y_offset);

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            double real = (x - WIDTH / 2.0) * data->scale + data->x_offset;
            double imag = (y - HEIGHT / 2.0) * data->scale + data->y_offset;
            int iter = calculate_julia(real, imag, data);
            *(int *)(img_data + (y * sl) + (x * 4)) = get_color(iter);
        }
    }
    mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
    mlx_destroy_image(data->mlx, img);
}
