/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:30:44 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/18 18:15:32 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
#define FRACTAL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

#include <stdio.h>
#include <stdlib.h> // exit()
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <math.h>

int ft_strcmp(char *s1,char *s2);
double atodbl(char *str);
void    draw_mandelbrot(void *mlx, void *win);
int cool_fractal(int argc, char **argv);
int cool_julia(int argc, char **argv);
int fractol(int argc, char **argv);


#endif