/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 06:10:58 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/28 20:59:57 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	free_julia(t_julia *julia)
{
	if (!julia)
		return ;
	if (julia->img)
	{
		mlx_destroy_image(julia->mlx, julia->img);
		julia->img = NULL;
	}
	if (julia->win)
	{
		mlx_destroy_window(julia->mlx, julia->win);
		julia->win = NULL;
	}
	if (julia->mlx)
	{
		mlx_destroy_display(julia->mlx);
		free(julia->mlx);
		julia->mlx = NULL;
	}
}

void	free_mandelbrot(t_mandelbrot *mandelbrot)
{
	if (!mandelbrot)
		return ;
	if (mandelbrot->img)
	{
		mlx_destroy_image(mandelbrot->mlx, mandelbrot->img);
		mandelbrot->img = NULL;
	}
	if (mandelbrot->win)
	{
		mlx_destroy_window(mandelbrot->mlx, mandelbrot->win);
		mandelbrot->win = NULL;
	}
	if (mandelbrot->mlx)
	{
		mlx_destroy_display(mandelbrot->mlx);
		free(mandelbrot->mlx);
		mandelbrot->mlx = NULL;
	}
}
