/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/22 09:20:41 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*void draw_mandelbrot(void *mlx, void *win)
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
                color = 0xFFFFFF - iter * 500;//gradient effect
             *(int *)(data + (y * size_line) + (x*4)) = color;//gradient effect
        }
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_destroy_image(mlx, img);
}

int mandelbrot(int argc, char **argv)
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
    if (!win)
        return (1);
    if (fractol(argc, argv) == 1)  // Changed from 0 to 1
        draw_mandelbrot(mlx, win);
    mlx_hook(win,17,0,close_window,NULL);
    mlx_key_hook(win, handle_key, NULL);
    mlx_loop(mlx);
    return (0);
}*/
/*#include "fractal.h"

static int calculate_mandelbrot(double real, double imag)
{
    double a;
    double b;
    
    double temp;
    int iter;
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
    int bpp, sl, endian;
    int x, y, iter;

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
}*/
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
