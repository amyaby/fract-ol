/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:27:25 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/27 18:25:52 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
         mandelbrot.zoom = 1.0;
        draw_mandelbrot(mlx, win, &mandelbrot);
         mlx_mouse_hook(win, handle_mouse_mandelbrot, &mandelbrot);
                 draw_mandelbrot(mlx, win, &mandelbrot);

    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        data = (t_julia){real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL,0 , 0, 0,1.0};
        draw_julia(&data);
          mlx_mouse_hook(win, handle_mouse_julia, &data);
                  draw_julia(&data);

    }
}

int main(int argc, char **argv)
{
    void *mlx;
    void *win;

    if (!fractol(argc, argv))
        return (1);

    if (!init_mlx(&mlx, &win))
        return (1);

    draw_fractal(mlx, win, argv);

    mlx_hook(win, 17, 0, close_window, NULL);
    mlx_key_hook(win, handle_key, NULL);

    mlx_loop(mlx);
    return (0);
}
