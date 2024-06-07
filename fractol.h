/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 17:55:06 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <float.h>

typedef struct s_args
{
		double	x;
		double	y;
}               t_args;

t_args	*create_struct(t_args *args);
void	*final_free(t_args *args)
void    *check_args(int argc, char **argv, t_args *args);
void    *check_four(char **argv, t_args *args);
void	*check_two(char **argv);
void	atoi_errors(char c);
double	atoi_calcul(const char *str, double r, int *i);
double	atoi_double(const char *str);






#endif