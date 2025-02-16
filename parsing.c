/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:07 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/16 12:49:20 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractal.h"

int fractol(int argc, char **argv)
{
    if (argc == 2)
    {
        if (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1], "burningship") != 0)
        {
            write(1, "___must be like this: mandelbrot or burningship___\n", 52);
            return 0;
        }
    }

    else if (argc == 4)
    {
        if (strcmp(argv[1], "julia") != 0)
        {
            write(1, "___must be like this: <real> <imaginary>___\n", 45);
            return 0;
        }
        else if (!atodbl(argv[2]) || !atodbl(argv[3]))
        {
            write(1, "___Both parameters for julia must be valid floating-point numbers___\n", 71);
            return 0;
        }
        double real = atodbl(argv[2]);
        double imaginary = atodbl(argv[3]);
    }

    else
    {
        write(1, "___Invalid number of arguments___\n", 34);
        return 0;
    }

    return 1;
}
int main(int argc, char **argv)
{
    fractol(argc,argv);
}