/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:27:25 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/27 04:42:45 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "fractal.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    
    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot");
    if (!win)
        return (1);
    raw_mandelbrot(mlx, win, mandelbrot);

    julia(argc, argv);
    mlx_hook(win,17,0,close_window,NULL);
    mlx_key_hook(win, handle_key, NULL);
    mlx_loop(mlx);
    return (0);
}*/
/*#include "fractal.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_mandelbrot mandelbrot;

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a new window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractal");
    if (!win)
        return (1);

    // Draw the appropriate fractal
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
        mandelbrot.scale = 4.0 / WIDTH;
        mandelbrot.x_offset = -2.0 + 1.25;
        mandelbrot.y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;
        draw_mandelbrot(mlx, win, &mandelbrot);
    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        julia(argc, argv);
    }

    // Set up hooks for key press and window close
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_key, NULL);

    // Start the MLX loop
    mlx_loop(mlx);
    return (0);
}*/
/*#include "fractal.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_mandelbrot mandelbrot;

    // Validate input arguments
    if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "julia") != 0))
    {
        write(1, "Usage: ./fractal <mandelbrot|julia> [real] [imaginary]\n", 56);
        return (1);
    }

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a new window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractal");
    if (!win)
        return (1);

    // Draw the appropriate fractal
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
        mandelbrot.scale = 4.0 / WIDTH;
        mandelbrot.x_offset = -2.0 + 1.25;
        mandelbrot.y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;
        draw_mandelbrot(mlx, win, &mandelbrot);
    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        if (argc != 4)
        {
            write(1, "Usage: ./fractal julia <real> <imaginary>\n", 42);
            return (1);
        }
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        t_julia data = {real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL, 0, 0, 0};
        draw_julia(&data);
    }

    // Set up hooks for key press and window close
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_key, NULL);

    // Start the MLX loop
    mlx_loop(mlx);
    return (0);
}*/
/*#include "fractal.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_mandelbrot mandelbrot;

    // Validate input arguments using fractol
    if (!fractol(argc, argv))
        return (1); // Exit if input is invalid

    // Initialize MLX
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a new window
    win = mlx_new_window(mlx, WIDTH, HEIGHT, "Fractal");
    if (!win)
        return (1);

    // Draw the appropriate fractal
    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
        mandelbrot.scale = 4.0 / WIDTH;
        mandelbrot.x_offset = -2.0 + 1.25;
        mandelbrot.y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;
        draw_mandelbrot(mlx, win, &mandelbrot);
    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        t_julia data = {real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL, 0, 0, 0};
        draw_julia(&data);
    }

    // Set up hooks for key press and window close
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_key, NULL);

    // Start the MLX loop
    mlx_loop(mlx);
    return (0);
}*/
#include "fractal.h"

static int init_mlx(void **mlx, void **win)
{
    *mlx = mlx_init();
    if (!*mlx)
        return (0);
    *win = mlx_new_window(*mlx, WIDTH, HEIGHT, "Fractal");
    if (!*win)
        return (0);
    return (1);
}

static void draw_fractal(void *mlx, void *win, char **argv)
{
    t_mandelbrot mandelbrot;
    t_julia data;

    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
        mandelbrot.scale = 4.0 / WIDTH;
        mandelbrot.x_offset = -2.0 + 1.25;
        mandelbrot.y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;
        draw_mandelbrot(mlx, win, &mandelbrot);
    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        data = (t_julia){real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL, 0, 0, 0};
        draw_julia(&data);
    }
}

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    // Validate input arguments using fractol
    if (!fractol(argc, argv))
        return (1); // Exit if input is invalid

    // Initialize MLX and create a window
    if (!init_mlx(&mlx, &win))
        return (1);

    // Draw the appropriate fractal
    draw_fractal(mlx, win, argv);

    // Set up hooks for key press and window close
    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_key, NULL);

    // Start the MLX loop
    mlx_loop(mlx);
    return (0);
}
