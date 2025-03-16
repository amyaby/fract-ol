/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:30:44 by iabasala          #+#    #+#             */
/*   Updated: 2025/03/15 23:49:49 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_julia
{
	double	c_re;
	double	c_im;
	double	scale;
	double	x_offset;
	double	y_offset;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		size_line;
	int		bpp;
	int		endian;
}			t_julia;

typedef struct s_mandelbrot
{
	double	real;
	double	imag;
	double	scale;
	double	x_offset;
	double	y_offset;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
	int		x;
	int		y;

}			t_mandelbrot;

int			fractol(int argc, char **argv);
void		draw_mandelbrot(t_mandelbrot *mandelbrot);
void		draw_julia(t_julia *data);
int			ft_isdigit(int c);


int			handle_key(int keycode, t_mandelbrot *data);
int			close_window_m(t_mandelbrot *data);
double		atodbl(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		draw_fractal(void *mlx, void *win, char **argv);
void		free_julia(t_julia *julia);
void		free_mandelbrot(t_mandelbrot *mandelbrot);
int			zoom_mandelbrot(int button, int x, int y, t_mandelbrot *data);
int			zoom_julia(int button, int x, int y, t_julia *data);
int			julia_main(t_julia *data);
int			mandelbrot_main(t_mandelbrot *data);
int			close_window_j(t_julia *data);

#endif
