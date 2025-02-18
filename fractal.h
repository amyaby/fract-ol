/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:30:44 by iabasala          #+#    #+#             */
/*   Updated: 2025/02/17 22:31:38 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
#define FRACTAL_H

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

#include <stdio.h>
#include <stdlib.h> // for exit()
#include"minilibx-linux/mlx_int.h"
#include "minilibx-linux/mlx.h"
#include <unistd.h>

int ft_strcmp(char *s1,char *s2);
double atodbl(char *str);

#endif