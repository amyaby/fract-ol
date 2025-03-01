/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:37 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/01 14:56:25 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	calculate_mandelbrot(double real, double imag)
{
	double	a;
	double	b;
	double	temp;
	int		iter;

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

static int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (0xFFFFFF - iter * 500);
}

void	draw_mandelbrot(t_mandelbrot *mandelbrot)
{
	int	iter;

	mandelbrot->img = mlx_new_image(mandelbrot->mlx, WIDTH, HEIGHT);
	mandelbrot->data = mlx_get_data_addr(mandelbrot->img, &mandelbrot->bpp,
			&mandelbrot->sl, &mandelbrot->endian);
	mandelbrot->y = -1;
	while (++mandelbrot->y < HEIGHT)
	{
		mandelbrot->x = -1;
		while (++mandelbrot->x < WIDTH)
		{
			mandelbrot->real = (mandelbrot->x - WIDTH / 2.0) * mandelbrot->scale
				+ mandelbrot->x_offset;
			mandelbrot->imag = (mandelbrot->y - HEIGHT / 2.0)
				* mandelbrot->scale + mandelbrot->y_offset;
			iter = calculate_mandelbrot(mandelbrot->real, mandelbrot->imag);
			*(int *)(mandelbrot->data + (mandelbrot->y * mandelbrot->sl)
					+ (mandelbrot->x * 4)) = get_color(iter);
		}
	}
	mlx_put_image_to_window(mandelbrot->mlx, mandelbrot->win, mandelbrot->img,
		0, 0);
	mlx_destroy_image(mandelbrot->mlx, mandelbrot->img);
}
