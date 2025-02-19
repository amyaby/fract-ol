#include "fractal.h"

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
    if (fractol(argc, argv) == 1)  // Changed from 0 to 1
        draw_mandelbrot(mlx, win);
    mlx_loop(mlx);
    return (0);
}