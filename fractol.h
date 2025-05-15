/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/23 20:22:26 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# define WIDTH	800
# define HEIGHT	800
# define ITERATIONS	40

typedef struct s_num
{
	double	x; //real
	double	y; // imaginary
}				t_num;

typedef struct s_img
{
	void	*img_add;
	char	*pix_add;
	int		bit_pix;
	int		length_line;
	int		endian;
}				t_img;

typedef struct s_data
{
	char	*name;
	int		range;
	void	*init;
	void	*window;
	t_img	*image;
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_data;

# define WHITE			0xFFFFFF
# define BLACK			0x0000
# define PASTEL_PINK	0xFFD1DC
# define PASTEL_BLUE	0xAEC6CF
# define PASTEL_GREEN	0x77DD77
# define PASTEL_YELLOW	0xFDFD96
# define PASTEL_PURPLE	0xC3B1E1
# define PASTEL_ORANGE	0xFFB347
# define PASTEL_RED     0xFF6961
# define PASTEL_GRAY    0xD3D3D3

void	*create_structs(t_data **data, int argc, char **argv);
void	*data_free(t_data *data);
void	*check_args(int argc, char **argv);
int		check_four(char **argv);
int		check_two(char **argv);
int		check_bonus(char **argv);
void	atoi_errors(char c);
double	atoi_calcul(const char *str, double r, int *i, int j);
double	atoi_double(const char *str, int i);
double	win_resize(double imgy, double old_max, double new_min, double new_max);
void	*implementation_struct(t_data *data, char *name);
t_num	calcul(t_num n1, t_num n2);
t_num	calcul_b(t_num z, t_num c);
void	*create_fractal(t_data *data);
void	man_manage_pixel(t_data *data, int x, int y);
void	init_events(t_data *data);
int		do_key(int key, t_data *data);
int		do_mouse(int button, int x, int y, t_data *data);
int		close_escape(t_data *data);
void	jul_manage_pixel(t_data *data, int x, int y);
void	put_pixel_image(t_img *image, int x, int y, int color);
int		go_darker(int trgb);
int		gradient_color(double t, int main_color, int darker_color);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		ground_color(t_data *data);
int		outline_color(t_data *data);
int		fractal_color(t_data *data);
void	bur_manage_pixel(t_data *data, int x, int y);

#endif