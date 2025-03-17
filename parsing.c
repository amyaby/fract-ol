/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:07 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/16 03:44:39 by iabasala         ###   ########.fr       */
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
			write(1, "___❌must be like this: mandelbrot or julia❌___\n", 52);
			return (0);
		}
	}
	return (1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_invalid_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0);
	else if (str[i] == '.' && i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		i++;
	else
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0' && i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		return (0);
	else
		return (1);
	return (0);
}

int	cool_julia(int argc, char **argv)
{
	double	real;
	double	imaginary;

	(void)argc;
	if (is_invalid_format(argv[2]) || is_invalid_format(argv[3]))
	{
		write(1, "❌Error: Invalid number format for Julia parameters\n", 53);
		return (0);
	}
	real = atodbl(argv[2]);
	imaginary = atodbl(argv[3]);
	return (1);
}

int	fractol(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			return (1);
		else
		{
			write(1, "___❌must be like this: mandelbrot or julia❌___\n", 52);
			return (0);
		}
	}
	if (argc == 4)
	{
		if (ft_strcmp(argv[1], "julia") == 0)
		{
			if (!cool_julia(argc, argv))
				return (0);
		}
		else
		{
			write(1, "___❌must be like this: mandelbrot or julia❌___\n", 52);
			return (0);
		}
		return (1);
	}
	return (write(1, "__❌invalid argument__", 22), 0);
}
