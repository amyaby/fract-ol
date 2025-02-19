/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:07 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/18 16:24:14 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

int cool_fractal(int argc, char **argv)
{
    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "burningship") != 0)
        {
            write(1, "___must be like this: mandelbrot or burningship___\n", 52);
            return (0);
        }
    }
    return (1);
}

int cool_julia(int argc, char **argv)
{
    if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
    {
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);

        if ((real == 0.0 && argv[2][0] != '0') || (imaginary == 0.0 && argv[3][0] != '0'))
        {
            write(1, "___invalid number___\n", 22);
            return (0);
        }
        return (1);
    }
    write(1, "___Invalid number of arguments___\n", 34);
    return (0);
}

int fractol(int argc, char **argv)
{
    if (argc == 2)
        return cool_fractal(argc, argv);
    if (argc == 4)
        return cool_julia(argc, argv);
    write(1, "___Invalid number of arguments___\n", 34);
    return (0);
}
int result(int argc, char **argv)
{
    return (fractol(argc, argv));
}


