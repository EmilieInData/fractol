/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/13 20:10:32 by esellier         ###   ########.fr       */
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
# include <float.h>
# include <math.h>

#define WIDTH	800
#define HEIGHT	800

typedef struct s_num 
{
	double	x; //real
	double	y; // imaginary
}               t_num;

typedef struct s_img // pixel buffer
{
	void	*img_add; // adresse de l'image
	char	*pix_add; // adresse du pixel actuel
	int		bit_pix;
	int		length_line;
	int		endian;
}				t_img;

typedef struct s_data
{
	//mlx
	void	*init;
	void	*window;
	t_img	*image;
	//hooks variables
	double	outside_fractal; // hypotenuse
	int		def_iterations;
}				t_data;

#define WHITE			0XFFFFFF
#define BLACK			0x000000
#define PASTEL_PINK		0xFFD1DC
#define PASTEL_BLUE		0xAEC6CF
#define PASTEL_GREEN	0x77DD77
#define PASTEL_YELLOW   0xFDFD96
#define PASTEL_PURPLE   0xC3B1E1
#define PASTEL_ORANGE   0xFFB347
#define PASTEL_RED      0xFF6961
#define PASTEL_TEAL     0x99C5C4
#define PASTEL_BROWN    0xCFCFC4
#define PASTEL_GRAY     0xD3D3D3

void	*create_structs(t_data **data);
void	*data_free(t_data *data);
void    *check_args(int argc, char **argv);
int		check_four(char **argv);
int		check_two(char **argv);
void	atoi_errors(char c);
double	atoi_calcul(const char *str, double r, int *i);
double	atoi_double(const char *str);
double  window_resize(double imaginary, double old_max, double new_min, double new_max);
void	*implementation_struct(t_data *data, char *name);
t_num	calcul(t_num n1, t_num n2);
void	*create_fractal(t_data *data);
void	manage_pixel(t_data *data, int x, int y);

#endif