/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:27:25 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 20:55:13 by iabasala         ###   ########.fr       */
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
    {
        mlx_destroy_display(*mlx);
        free(*mlx);
        return (0); 
    }
       
    return (1);
}

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
         mandelbrot_main(mandelbrot);
         free_mandelbrot(&mandelbrot);

    }
    else if (ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
        data = (t_julia){real, imaginary, 4.0 / WIDTH, 0.0, 0.0, mlx, win, NULL, NULL,0 , 0, 0};
        julia_main(data);

             free_julia(&data);


    }
}

int julia_main(t_julia data)
{
    draw_julia(&data);
    mlx_hook(data.win, 17, 0, close_window, NULL);
    mlx_key_hook(data.win, handle_key, NULL);

    mlx_mouse_hook(data.win, zoom_julia, &data);
    mlx_loop(data.mlx);
    free_julia(&data);
    return (0);
}
int mandelbrot_main( t_mandelbrot data)
{
    draw_mandelbrot(&data);
    mlx_hook(data.win, 17, 0, close_window, NULL);
    mlx_key_hook(data.win, handle_key, NULL);

    mlx_mouse_hook(data.win, zoom_mandelbrot, &data);
    
    mlx_loop(data.mlx);
        free_mandelbrot(&data);

    return (0);
}
int main(int argc, char**argv)
{
    (void)argc;
     void *mlx;
    void *win;
    if(!fractol(argc, argv))
            return 0;
    if(!init_mlx(&mlx, &win))
    {
         if (mlx) free(mlx);
         return 1;
    }
        
    draw_fractal(mlx, win, argv);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
    return 0;
}
