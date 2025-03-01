/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:07 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/01 14:56:40 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	cool_mandelbrot(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
				"julia") != 0)
		{
			write(1, "___must be like this: mandelbrot or julia___\n", 46);
			return (0);
		}
	}
	return (1);
}

int	cool_julia(int argc, char **argv)
{
	double	real;
	double	imaginary;

	if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		real = atodbl(argv[2]);
		imaginary = atodbl(argv[3]);
		if ((real == 0.0 && (argv[2][0] != '0' || argv[2][1] != '\0')) ||
			(imaginary == 0.0 && (argv[3][0] != '0' || argv[3][1] != '\0')))
		{
			write(1, "Error: Invalid number format for Julia parameters\n", 51);
			return (0);
		}
		return (1);
	}
	write(1, "___Invalid number of arguments___\n", 34);
	return (0);
}

int	fractol(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			return (1);
		}
		else if (ft_strcmp(argv[1], "julia") == 0)
		{
			write(1, "___Julia requires real and imaginary parameters___\n",
				51);
			return (0);
		}
		else
		{
			write(1, "___must be like this: mandelbrot or julia___\n", 46);
			return (0);
		}
	}
	if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		return (cool_julia(argc, argv));
	}
	write(1, "___Invalid number of arguments___\n", 34);
	return (0);
}
