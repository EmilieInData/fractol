/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:26:47 by esellier          #+#    #+#             */
/*   Updated: 2024/06/07 12:32:43 by esellier         ###   ########.fr       */
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
		char    ??
}               t_args;

void    *args_errors(int argc, char **argv);
void    *errors_four(int argc, char **argv);
void    *errors_two(int argc, char **argv);




#endif