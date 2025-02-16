#include "fractol.h"


<<<<<<< HEAD:test.c
=======
int handle_key(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307) // Escape key
        exit(0);
    return (0);
}
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}
>>>>>>> 55a67aca3dcc01f19c0dd05850a46f5f5bac3f2b:main.c

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "playing");
    mlx_hook(win,17,0,close_window,NULL);
    mlx_key_hook(win, handle_key, NULL);
   //  mlx_pixel_put(mlx, win, 400, 300, 0xFF0000);
   //       mlx_pixel_put(mlx, win, 399, 299, 0xFF0000);
   //  mlx_pixel_put(mlx, win, 398, 298, 0xFF0000);
//   int x = 200;
//     while (x <= 600)  // Draw horizontal line
//     {
//         mlx_pixel_put(mlx, win, x, 100, 0xFF0000); // Red color
//         x++;
//     }
int y = 250;
    while (y < 325)  // Square height
    {
      int  x = 350;
        while (x < 450)  // Square width
        {
            mlx_pixel_put(mlx, win, x, y, 0x0000FF); // Blue color
            x++;
        }
        y++;
    }
    mlx_loop(mlx);
    return (0);
}


