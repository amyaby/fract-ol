/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:27:25 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 16:04:44 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

// static int init_mlx(void **mlx, void **win)
// {
//     *mlx = mlx_init();
//     if (!*mlx)
//         return (0);
//     *win = mlx_new_window(*mlx, WIDTH, HEIGHT, "Fractal");
//     if (!*win)
//         return (0);
//     return (1);
// }

void draw_fractal(void *mlx, void *win, char **argv)
{
    t_mandelbrot mandelbrot;
    t_julia data;

    if (ft_strcmp(argv[1], "mandelbrot") == 0)
    {
         mandelbrot.scale = 4.0 / WIDTH;
        mandelbrot.x_offset = -2.0 + 1.25;
        mandelbrot.y_offset = -3.0 + (HEIGHT / WIDTH) * 2.0 + 1.0;
        mandelbrot.mlx = mlx;
        mandelbrot.win = win;
        //mandelbrot.x_offset = -0.75;
       // mandelbrot.y_offset = 0.0;
        draw_mandelbrot(&mandelbrot);
         mlx_mouse_hook(win, zoom_mandelbrot, &mandelbrot);
         // draw_mandelbrot(mlx, win, &mandelbrot);
        // free_mandelbrot(&mandelbrot);

    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        data = (t_julia){real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL,0 , 0, 0};
        draw_julia(&data);
           //mlx_mouse_hook(win, zoom_julia, &data);

              // draw_julia(&data);

            //   free_julia(&data);


    }
}

int main()
{
    t_mandelbrot data;

    // if (!fractol(argc, argv))
    //     return (1);

    // if (!init_mlx(&mlx, &win))
    //     return (1);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractal");
    data = (t_mandelbrot){0, 0, 5.0 / WIDTH, 0.0, 0.0, data.mlx, data.win, NULL, NULL, 0, 0,0,0,0};
    draw_mandelbrot(&data);
    mlx_hook(data.win, 17, 0, close_window, NULL);
    mlx_key_hook(data.win, handle_key, NULL);
    mlx_mouse_hook(data.win, zoom_mandelbrot, &data);
    mlx_loop(data.mlx);
    return (0);
}
