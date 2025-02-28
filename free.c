/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:10:58 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 07:39:47 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
void free_julia(t_julia *julia)
{
    mlx_destroy_image(julia->mlx, julia->img);
     mlx_destroy_window(julia->mlx, julia->win);
      mlx_destroy_display(julia->mlx);
    
    free(julia->mlx);
}
void free_mandelbrot(t_mandelbrot *mandelbrot)
{
    mlx_destroy_image(mandelbrot->mlx, mandelbrot->img);
     mlx_destroy_window(mandelbrot->mlx, mandelbrot->win);
      mlx_destroy_display(mandelbrot->mlx);
    
   free(mandelbrot->mlx);
}