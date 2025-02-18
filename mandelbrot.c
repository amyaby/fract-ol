/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/17 23:34:33 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractal.h>

void maindelbort()
{
for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            // Convert pixel (x, y) to complex number C
            // Run Mandelbrot iteration
            // Choose color based on iteration count
            // Set the pixel color in image
        }
    }
}
int main()
{
    void *mlx;
    void *win;
    mlx = mlix_init();
    win = mlx_new_window(mlx, 800, 800, "mandelbrot");
}