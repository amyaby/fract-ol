/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:07 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/01 21:55:25 by iabasala         ###   ########.fr       */
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
/*void	cool_julia(int argc, char **argv)
{
	double	real;
	double	imaginary;

	if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
	{
		if (argv[2][0] == '.' || argv[3][0] == '.')
		{
			write(1, "Error: Invalid number format for Julia parameters\n", 51);
			return (0);
		}

		if ((argv[2][0] == '+' || argv[2][0] == '-') &&
			(argv[2][1] == '+' || argv[2][1] == '-'))
		{
			write(1, "Error: Invalid number format for Julia parameters\n", 51);
			return (0);
		}
		if ((argv[3][0] == '+' || argv[3][0] == '-') &&
			(argv[3][1] == '+' || argv[3][1] == '-'))
		{
			write(1, "Error: Invalid number format for Julia parameters\n", 51);
			return (0);
		}

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
}*/
int	is_invalid_format(char *str)
{
	if (str[0] == '.' || ((str[0] == '+' || str[0] == '-') &&
		(str[1] == '+' || str[1] == '-')))
		return (1);
	return (0);
}

void	cool_julia(int argc, char **argv)
{
	double	real;
	double	imaginary;

	if (argc != 4 || ft_strcmp(argv[1], "julia") != 0)
	{
		write(1, "___Invalid number of arguments___\n", 34);
		return;
	}
	if (is_invalid_format(argv[2]) || is_invalid_format(argv[3]))
	{
		write(1, "Error: Invalid number format for Julia parameters\n", 51);
		return;
	}
	real = atodbl(argv[2]);
	imaginary = atodbl(argv[3]);
	if ((real == 0.0 && (argv[2][0] != '0' || argv[2][1] != '\0')) ||
		(imaginary == 0.0 && (argv[3][0] != '0' || argv[3][1] != '\0')))
	{
		write(1, "Error: Invalid number format for Julia parameters\n", 51);
		return;
	}
}



int fractol(int argc, char **argv)
{
    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
            return (1);  // Continue drawing Mandelbrot fractal
        else if (ft_strcmp(argv[1], "julia") == 0)
        {
            write(1, "___Julia requires real and imaginary parameters___\n", 51);
            return (0);  // Don't proceed if Julia parameters are missing
        }
        else
        {
            write(1, "___must be like this: mandelbrot or julia___\n", 46);
            return (0);  // Invalid fractal type
        }  
    } 
    // For Julia with 4 arguments (including 'julia' + 2 numbers)
    if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
    {
        cool_julia(argc, argv);  // Validate the input parameters for Julia
        return (1);  // Proceed to drawing the Julia fractal (or Mandelbrot if needed)
    }
    write(1, "___Invalid number of arguments___\n", 34);
    return (0);  // Invalid number of arguments
}


