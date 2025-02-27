/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:30:44 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/27 04:56:58 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
#define FRACTAL_H

#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

typedef struct s_mandelbrot
{
    double real;
    double imag;
    double scale;
    double x_offset;
    double y_offset;
} t_mandelbrot;

typedef struct s_julia
{
    double c_re;
    double c_im;
    double scale;
    double x_offset;
    double y_offset;
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int size_line;
    int bpp;
    int endian;
} t_julia;

int     fractol(int argc, char **argv);
void    draw_mandelbrot(void *mlx, void *win, t_mandelbrot *mandelbrot);
void    draw_julia(t_julia *data);
int     handle_key(int keycode, void *param);
int     close_window(void *param);
double  atodbl(char *str);
int     ft_strcmp(const char *s1, const char *s2);

#endif