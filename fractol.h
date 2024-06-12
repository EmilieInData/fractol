/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/12 20:48:06 by esellier         ###   ########.fr       */
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
	void	*img_add; // point sur la struct de límage
	char	*pix_add; // adress du pixel actuel
	int		bit_pix;
	int		length_line;
	int		endian;
}				t_img;

typedef struct s_fractal
{
	//mlx
	void	*init; // init
	void	*window; // new_window
	// image
	t_img	image;
	//hooks variables	
}				t_fractal;

//t_args	*create_struct(t_args *args);
//void	*final_free(t_num *num);
void    *check_args(int argc, char **argv);
int		check_four(char **argv);
int		check_two(char **argv);
void	atoi_errors(char c);
double	atoi_calcul(const char *str, double r, int *i);
double	atoi_double(const char *str);
double  window_resize(double imaginary, double old_max, double new_min, double new_max);
void	*create_struct(t_fractal *fractal, t_img *image, char *name);


#endif